#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <windows.h>

using namespace std;

extern "C"
{

    __declspec(dllexport) void save_product(char *nume, int cantitate, float pret)
    {
        ofstream fout("products.txt", ios::app);
        if (fout.is_open())
        {
            fout << nume << "," << cantitate << "," << pret << "\n";
            fout.close();
        }
    }

    __declspec(dllexport) void read_all_products(char *buffer, int bufferSize)
    {
        ifstream fin("products.txt");
        ostringstream oss;
        string line;

        while (getline(fin, line))
        {
            oss << line << "\n";
        }

        string result = oss.str();
        strncpy(buffer, result.c_str(), bufferSize - 1);
        buffer[bufferSize - 1] = '\0';
    }

    __declspec(dllexport) void delete_product_by_name(const char *nameToDelete)
    {
        ifstream fin("products.txt");
        ofstream fout("temp.txt");

        string line;
        while (getline(fin, line))
        {
            if (line.substr(0, line.find(',')) != nameToDelete)
            {
                fout << line << "\n";
            }
        }

        fin.close();
        fout.close();
        remove("products.txt");
        rename("temp.txt", "products.txt");
    }

    __declspec(dllexport) void update_product(char *nameToUpdate, int newQuantity, float newPrice)
    {
        ifstream fin("products.txt");
        ofstream fout("temp.txt");

        string line;
        while (getline(fin, line))
        {
            string currentName = line.substr(0, line.find(','));
            if (currentName == nameToUpdate)
            {
                fout << nameToUpdate << "," << newQuantity << "," << newPrice << "\n";
            }
            else
            {
                fout << line << "\n";
            }
        }

        fin.close();
        fout.close();
        remove("products.txt");
        rename("temp.txt", "products.txt");
    }

    __declspec(dllexport) char* show_product(char *nameToFind)
    {
        ifstream fin("products.txt");
        string line;
        while (getline(fin, line))
        {
            string currentName = line.substr(0, line.find(','));
            if (currentName == nameToFind)
            {
                string quantity = line.substr(line.find(','), line.find(',') + 1);
                char* out = new char[quantity.size() + 1];  
                strcpy(out, quantity.c_str());             
                return out;    
            }
        }
        fin.close();
        char* none  = new char[5];
        strcpy(none, "None");
        return none;
    }
}