import tkinter as tk
from tkinter import messagebox, ttk
from ctypes import CDLL, c_char_p, c_int, c_float, create_string_buffer, c_bool
import os

lib = CDLL("D:\\Code\\Gestionare Stocuri\\products.dll") 
lib.save_product.argtypes = [c_char_p, c_int, c_float]
lib.read_all_products.argtypes = [c_char_p, c_int]
lib.delete_product_by_name.argtypes = [c_char_p]
lib.update_product.argtypes = [c_char_p, c_int, c_float]
lib.show_product.restype = c_char_p

root = tk.Tk()
root.title("Stock's Manager")
root.iconbitmap("D:\\Code\\Gestionare Stocuri\\logo.ico")

frame_form = tk.Frame(root)
frame_form.pack()

tk.Label(frame_form, text="Nume:").grid(row=0, column=0)
entry_name = tk.Entry(frame_form)
entry_name.grid(row=0, column=1)

tk.Label(frame_form, text="Cantitate:").grid(row=1, column=0)
entry_quantity = tk.Entry(frame_form)
entry_quantity.grid(row=1, column=1)

tk.Label(frame_form, text="Preț:").grid(row=2, column=0)
entry_price = tk.Entry(frame_form)
entry_price.grid(row=2, column=1)

selected_name = None

def salveaza():
    global selected_name
    name = entry_name.get()
    try:
        quantity = int(entry_quantity.get())
        price = float(entry_price.get())
    except ValueError:
        messagebox.showerror("Eroare", "Date invalide.")
        return

    if selected_name:
        lib.update_product(selected_name.encode(), quantity, price)
        selected_name = None
    else:
        lib.save_product(name.encode(), quantity, price)

    reincarca_tabel()
    sterge_inputuri()

def reincarca_tabel():
    buffer = create_string_buffer(5000)
    lib.read_all_products(buffer, 5000)
    data = buffer.value.decode('utf-8').strip().split("\n")

    for row in tree.get_children():
        tree.delete(row)

    for line in data:
        if line.strip() == "":
            continue
        parts = line.split(',')
        if len(parts) == 3:
            tree.insert("", "end", values=(parts[0], parts[1], parts[2]))

def sterge_inputuri():
    entry_name.delete(0, tk.END)
    entry_quantity.delete(0, tk.END)
    entry_price.delete(0, tk.END)

def selecteaza_produs():
    global selected_name
    selected = tree.focus()
    if selected:
        values = tree.item(selected, 'values')
        if values:
            selected_name = values[0]
            entry_name.delete(0, tk.END)
            entry_quantity.delete(0, tk.END)
            entry_price.delete(0, tk.END)
            entry_name.insert(0, values[0])
            entry_quantity.insert(0, values[1])
            entry_price.insert(0, values[2])

def sterge_produs():
    selected = tree.focus()
    if selected:
        values = tree.item(selected, 'values')
        if values:
            lib.delete_product_by_name(values[0].encode())
            reincarca_tabel()
            sterge_inputuri()

def cauta_produs():
    name = entry_name.get()
    quantity = lib.show_product(name.encode())
    if quantity != "None":
        messagebox.showinfo("Găsit", f"Exista '{quantity}' de '{name}'.")
    else:
        messagebox.showwarning("Negăsit", f"Produsul '{name}' NU există.")

tk.Button(frame_form, text="Salvează", command=salveaza).grid(row=3, column=0, columnspan=2)
tk.Button(frame_form, text="Selectează pentru editare", command=selecteaza_produs).grid(row=4, column=0, columnspan=2)
tk.Button(frame_form, text="Caută produs", command=cauta_produs).grid(row=5, column=0, columnspan=2)

frame_table = tk.Frame(root)
frame_table.pack(pady=10)

tree = ttk.Treeview(frame_table, columns=("Nume", "Cantitate", "Preț"), show="headings")
tree.heading("Nume", text="Nume")
tree.heading("Cantitate", text="Cantitate")
tree.heading("Preț", text="Preț")
tree.pack()

tk.Button(root, text="Șterge produs selectat", command=sterge_produs).pack()

reincarca_tabel()
root.mainloop()