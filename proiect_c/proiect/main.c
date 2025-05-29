#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
typedef struct
{
    int total_caractere;
    int caractere_fara_spatii;
    int total_cuvinte;
    int total_propozitii;
    int total_paragrafe;
    int total_linii;
    int litere_mari;
    int litere_mici;
    int cifre;
    int punctuatie;
    int spatii;
    int lungime_cel_mai_lung_cuvant;
    double lungime_medie_cuvant;
    double lungime_medie_propozitie;
    int numar_silabe;
} StatisticiText;

GtkWidget *vizualizare_text;
GtkWidget *eticheta_statistici;
GtkWidget *fereastra_principala;

int numara_silabe(const char *cuvant)
{
    int numar = 0;
    int lungime = strlen(cuvant);
    int vocala_anterioara = 0;

    for (int i = 0; i < lungime; i++)
    {
        char c = tolower(cuvant[i]);
        int este_vocala = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
        if (este_vocala && !vocala_anterioara)
            numar++;
        vocala_anterioara = este_vocala;
    }
    return numar > 0 ? numar : 1;
}
StatisticiText analizeaza_text(const char *text)
{
    StatisticiText statistici = {0};
    int in_cuvant = 0;
    int lungime_cuvant_curent = 0;
    int lungime_totala_cuvinte = 0;
    char cuvant_curent[256] = {0};
    int index_cuvant = 0;
    if (!text || strlen(text) == 0)
        return statistici;
    statistici.total_caractere = strlen(text);
    statistici.total_paragrafe = 1;
    statistici.total_linii = 1;
    for (int i = 0; i < statistici.total_caractere; i++)
    {
        char c = text[i];
        if (c != ' ' && c != '\t' && c != '\n' && c != '\r')
            statistici.caractere_fara_spatii++;
        if (isupper(c))
            statistici.litere_mari++;
        else if (islower(c))
            statistici.litere_mici++;
        else if (isdigit(c))
            statistici.cifre++;
        else if (ispunct(c))
            statistici.punctuatie++;
        else if (isspace(c))
            statistici.spatii++;
        if (c == '\n')
        {
            statistici.total_linii++;
            if (i > 0 && text[i-1] == '\n')
                statistici.total_paragrafe++;
        }
        if (isalnum(c) || c == '\'')
        {
            if (!in_cuvant)
            {
                in_cuvant = 1;
                lungime_cuvant_curent = 0;
                index_cuvant = 0;
                memset(cuvant_curent, 0, sizeof(cuvant_curent));
            }
            lungime_cuvant_curent++;
            if (index_cuvant < 255)
                cuvant_curent[index_cuvant++] = c;
        }
        else
            if (in_cuvant)
            {
                statistici.total_cuvinte++;
                lungime_totala_cuvinte += lungime_cuvant_curent;
                if (lungime_cuvant_curent > statistici.lungime_cel_mai_lung_cuvant)
                    statistici.lungime_cel_mai_lung_cuvant = lungime_cuvant_curent;
                statistici.numar_silabe += numara_silabe(cuvant_curent);
                in_cuvant = 0;
            }
        if (c == '.' || c == '!' || c == '?')
            statistici.total_propozitii++;
    }
    if (in_cuvant)
    {
        statistici.total_cuvinte++;
        lungime_totala_cuvinte += lungime_cuvant_curent;
        if (lungime_cuvant_curent > statistici.lungime_cel_mai_lung_cuvant)
            statistici.lungime_cel_mai_lung_cuvant = lungime_cuvant_curent;
        statistici.numar_silabe += numara_silabe(cuvant_curent);
    }
    if (statistici.total_cuvinte > 0)
        statistici.lungime_medie_cuvant = (double)lungime_totala_cuvinte / statistici.total_cuvinte;
    if (statistici.total_propozitii > 0)
        statistici.lungime_medie_propozitie = (double)statistici.total_cuvinte / statistici.total_propozitii;
    return statistici;
}
void actualizeaza_statistici() {
    GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(vizualizare_text));
    GtkTextIter inceput, sfarsit;

    gtk_text_buffer_get_start_iter(buffer, &inceput);
    gtk_text_buffer_get_end_iter(buffer, &sfarsit);

    char *text = gtk_text_buffer_get_text(buffer, &inceput, &sfarsit, FALSE);

    StatisticiText statistici = analizeaza_text(text);

    char text_statistici[2048];
    snprintf(text_statistici, sizeof(text_statistici),
        "<b> STATISTICI TEXT</b>\n\n"
        "<b>Analiza de baza a textului:</b>\n"
        " Total Caractere: %d\n"
        " Caractere (fara spatii): %d\n"
        " Cuvinte: %d\n"
        " Propozitii: %d\n"
        " Paragrafe: %d\n"
        " Linii: %d\n\n"
        "<b>Analiza caracterelor:</b>\n"
        " Litere Mari: %d\n"
        " Litere Mici: %d\n"
        " Cifre: %d\n"
        " Punctuatie: %d\n"
        " Spatii: %d\n\n"
        "<b>Analiza cuvintelor:</b>\n"
        " Cel mai lung cuvânt: %d caractere\n"
        " Lungimea medie a cuvantului: %.1f caractere\n"
        " Total silabe: %d\n\n"
        "<b>Analiza propozitiilor:</b>\n"
        " Lungimea medie a propozitiei: %.1f cuvinte\n",

        statistici.total_caractere, statistici.caractere_fara_spatii,statistici.total_cuvinte, statistici.total_propozitii,
        statistici.total_paragrafe, statistici.total_linii, statistici.litere_mari, statistici.litere_mici,
        statistici.cifre, statistici.punctuatie, statistici.spatii, statistici.lungime_cel_mai_lung_cuvant,
        statistici.lungime_medie_cuvant, statistici.numar_silabe, statistici.lungime_medie_propozitie);

    gtk_label_set_markup(GTK_LABEL(eticheta_statistici), text_statistici);

    g_free(text);
}
void schimbare_txt(GtkTextBuffer *buffer, gpointer date_utilizator)
{
    actualizeaza_statistici();
}
void stergere(GtkWidget *widget, gpointer date)
{
    GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(vizualizare_text));
    gtk_text_buffer_set_text(buffer, "", 0);
}
void incarcare_fisier(GtkWidget *widget, gpointer date)
{
    GtkWidget *dialog;
    GtkFileChooserAction actiune = GTK_FILE_CHOOSER_ACTION_OPEN;
    gint rezultat;

    dialog = gtk_file_chooser_dialog_new("Deschide Fișier", GTK_WINDOW(fereastra_principala), actiune, "Anulează", GTK_RESPONSE_CANCEL, "Deschide",GTK_RESPONSE_ACCEPT,NULL);

    GtkFileFilter *filtru = gtk_file_filter_new();
    gtk_file_filter_set_name(filtru, "Fișiere text");
    gtk_file_filter_add_pattern(filtru, "*.txt");

    gtk_file_chooser_add_filter(GTK_FILE_CHOOSER(dialog), filtru);

    filtru = gtk_file_filter_new();
    gtk_file_filter_set_name(filtru, "Toate fișierele");
    gtk_file_filter_add_pattern(filtru, "*");
    gtk_file_chooser_add_filter(GTK_FILE_CHOOSER(dialog), filtru);

    rezultat = gtk_dialog_run(GTK_DIALOG(dialog));
    if (rezultat == GTK_RESPONSE_ACCEPT)
    {
        char *nume_fisier;
        GtkFileChooser *selector = GTK_FILE_CHOOSER(dialog);
        nume_fisier = gtk_file_chooser_get_filename(selector);

        FILE *fisier = fopen(nume_fisier, "r");
        if (fisier)
        {
            fseek(fisier, 0, SEEK_END);
            long lungime = ftell(fisier);
            fseek(fisier, 0, SEEK_SET);

            char *continut = malloc(lungime + 1);
            if (continut)
            {
                fread(continut, 1, lungime, fisier);
                continut[lungime] = '\0';

                GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(vizualizare_text));
                gtk_text_buffer_set_text(buffer, continut, -1);

                free(continut);
            }
            fclose(fisier);
        }
        g_free(nume_fisier);
    }
    gtk_widget_destroy(dialog);
}
int main(int argc, char *argv[])
{
    gtk_init(&argc, &argv);

    fereastra_principala = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(fereastra_principala), "Analizor de Text");
    gtk_window_set_default_size(GTK_WINDOW(fereastra_principala), 1000, 600);
    gtk_container_set_border_width(GTK_CONTAINER(fereastra_principala), 10);

    GtkWidget *caseta_principala = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);
    gtk_container_add(GTK_CONTAINER(fereastra_principala), caseta_principala);

    GtkWidget *caseta_stanga = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_box_pack_start(GTK_BOX(caseta_principala), caseta_stanga, TRUE, TRUE, 0);

    GtkWidget *introducere_text = gtk_label_new(NULL);
    gtk_label_set_markup(GTK_LABEL(introducere_text), "<b> Introduceti textul:</b>");
    gtk_widget_set_halign(introducere_text, GTK_ALIGN_START);
    gtk_box_pack_start(GTK_BOX(caseta_stanga), introducere_text, FALSE, FALSE, 0);

    GtkWidget *fereastra_derulata = gtk_scrolled_window_new(NULL, NULL);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(fereastra_derulata), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    gtk_box_pack_start(GTK_BOX(caseta_stanga), fereastra_derulata, TRUE, TRUE, 0);

    vizualizare_text = gtk_text_view_new();
    gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(vizualizare_text), GTK_WRAP_WORD);
    gtk_container_add(GTK_CONTAINER(fereastra_derulata), vizualizare_text);

    GtkWidget *caseta_butoane = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
    gtk_box_pack_start(GTK_BOX(caseta_stanga), caseta_butoane, FALSE, FALSE, 5);

    GtkWidget *buton_stergere = gtk_button_new_with_label("Sterge Text");
    gtk_box_pack_start(GTK_BOX(caseta_butoane), buton_stergere, FALSE, FALSE, 0);

    GtkWidget *buton_incarcare = gtk_button_new_with_label("Incarca Fisier");
    gtk_box_pack_start(GTK_BOX(caseta_butoane), buton_incarcare, FALSE, FALSE, 0);

    GtkWidget *caseta_dreapta = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_box_pack_start(GTK_BOX(caseta_principala), caseta_dreapta, FALSE, FALSE, 0);

    GtkWidget *statistici = gtk_scrolled_window_new(NULL, NULL);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(statistici), GTK_POLICY_NEVER, GTK_POLICY_AUTOMATIC);
    gtk_widget_set_size_request(statistici, 350, -1);
    gtk_box_pack_start(GTK_BOX(caseta_dreapta), statistici, TRUE, TRUE, 0);

    eticheta_statistici = gtk_label_new("Introduceti text pentru a vedea statisticile");
    gtk_label_set_markup(GTK_LABEL(eticheta_statistici), "Introduceti text pentru a vedea statisticile");
    gtk_widget_set_halign(eticheta_statistici, GTK_ALIGN_START);
    gtk_widget_set_valign(eticheta_statistici, GTK_ALIGN_START);
    gtk_label_set_selectable(GTK_LABEL(eticheta_statistici), TRUE);
    gtk_container_add(GTK_CONTAINER(statistici), eticheta_statistici);

    GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(vizualizare_text));
    g_signal_connect(buffer, "changed", G_CALLBACK(schimbare_txt), NULL);
    g_signal_connect(buton_stergere, "clicked", G_CALLBACK(stergere), NULL);
    g_signal_connect(buton_incarcare, "clicked", G_CALLBACK(incarcare_fisier), NULL);
    g_signal_connect(fereastra_principala, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_widget_show_all(fereastra_principala);
    gtk_main();

    return 0;
}
