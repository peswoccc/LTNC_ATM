
void onead_xemtk()
{
    vector<tai_khoan> tk = file_to_tk();
    cout << setw(5) << left << text[3][language] << setw(20) << left << text[4][language] << " " << setw(20) << left << text[5][language] << " " << setw(20) << left << text[6][language] << setw(15) << left << text[7][language] << endl;
    for (int i = 0; i < tk.size(); i++)
        cout << setw(5) << left << i+1 << setw(20) << left << tk[i].id << " " << setw(20) << left << tk[i].pass << " " << setw(20) << left << tk[i].id_money << setw(15) << left << (tk[i].locked ? text[9][language] : text[8][language]) << endl;
}

bool id_exist(string id, vector<tai_khoan> tk)
{
    for (int i = 0; i < tk.size(); i++)
        if (id == tk[i].id) return 1;
    return 0;
}

bool id_valid(string id)
{
    if (id.size() > 20) return 0;
    bool a = 0;
    for (int i = 0; i < id.size(); i++)
    {
        a = 0;
        if (id[i] == '_') a = 1;
        if (id[i] >= 'a' && id[i] <= 'z') a = 1;
        if (id[i] >= 'A' && id[i] <= 'Z') a = 1;
        if (id[i] >= '0' && id[i] <= '9') a = 1;
        if (!a) return 0;
    }
    return 1;
}

void twoad_themtk()
{
    tai_khoan tam;
    cout << text[10][language];
    cin >> tam.id;
    while (!id_valid(tam.id))
    {
        system("cls");
        cout << text[15][language] << text[11][language];
        cin >> tam.id;
    }
    while (id_exist(tam.id, file_to_tk()))
    {
        system("cls");
        cout << text[15][language] << text[12][language];
        cin >> tam.id;
    }
    system("cls");
    cout << text[17][language] << tam.id << endl << text[13][language];
    cin >> tam.pass;
    while (!id_valid(tam.pass))
    {
        system("cls");
        cout << text[17][language] << tam.id << endl << text[15][language] << text[14][language];
        cin >> tam.pass;
    }
    tam.id_money = 0;
    tam.locked = 0;
    vector<tai_khoan> tk = file_to_tk();
    tk.push_back(tam);
    tk_to_file(tk);
    system("cls");
    cout << text[16][language];
}

void threead_unlock()
{
    string id;
    cout << text[18][language];
    cin >> id;
    while(!id_exist(id, file_to_tk()))
    {
        system("cls");
        cout << text[19][language];
        cin >> id;
    }
    vector<tai_khoan> tk = file_to_tk();
    for (int i = 0; i < tk.size(); i++)
        if (id == tk[i].id)
            tk[i].locked = 0;
    tk_to_file(tk);
    system("cls");
    cout << text[20][language] << id << text[23][language];
}

void fourad_tracuu_money()
{
    int k10, k20, k50, k100, k200, k500;
    file_to_money(k10, k20, k50, k100, k200, k500);
    cout << setw(20) << left << text[21][language] << text[22][language] << endl;
    cout << setw(20) << left << "10000" << k10 << endl;
    cout << setw(20) << left << "20000" << k20 << endl;
    cout << setw(20) << left << "50000" << k50 << endl;
    cout << setw(20) << left << "100000" << k100 << endl;
    cout << setw(20) << left << "200000" << k200 << endl;
    cout << setw(20) << left << "500000" << k500 << endl;
}

void fivead_add_money()
{
    cout << text[24][language];
    int a[7];
    string menh_gia[] = {"", "10000 VND", "20000 VND", "50000 VND", "100000 VND", "200000 VND", "500000 VND"};
    file_to_money(a[1], a[2], a[3], a[4], a[5], a[6]);
    int x, soto;
    cin >> x;
    cout << text[25][language] << menh_gia[x] << text[26][language];
    cin >> soto;
    a[x]+= soto;
    cout << text[27][language];
    int lai;
    cin >> lai;
    while (lai == 1)
    {
        system("cls");
        cout << text[24][language];
        cin >> x;
        cout << text[25][language] << menh_gia[x] << text[26][language];
        cin >> soto;
        a[x]+= soto;
        cout << text[27][language];
        cin >> lai;
    }
    system("cls");
    money_to_file(a[1], a[2], a[3], a[4], a[5], a[6]);
}

void sixad_history()
{
    cout << setw(22) << left << text[4][language] << setw(22) << left << text[28][language] << setw(40) << left << text[29][language] << text[30][language] << endl;
    ifstream f;
    if (language == 1) f.open("history1.txt");
    else f.open("history2.txt");
    while(!f.eof())
    {
        string s;
        getline(f,s);
        if (s != "") cout << s << endl;
    }
    f.close();
}

void sevenad_delete_history()
{
    remove("history1.txt");
    remove("history2.txt");
    ofstream("history1.txt");
    ofstream("history2.txt");
    cout << text[31][language];
}

void ad_min(tai_khoan &tk, vector <tai_khoan> &v)
{
    cout << text[32][language];
    string x;
    cin >> x;
    while (x.size() != 1 || x[0] < '1' || x[0] > '8')
    {
        system("cls");
        cout << text[32][language];
        cout << text[62][language];
        cin >> x;
    }
    system("cls");
    if (x == "1")
    {
        onead_xemtk();
        again(ad_min(tk, v));
    }
    else if (x == "2")
    {
        twoad_themtk();
        again(ad_min(tk, v));
    }
    else if (x == "3")
    {
        threead_unlock();
        again(ad_min(tk, v));
    }
    else if (x == "4")
    {
        fourad_tracuu_money();
        again(ad_min(tk, v));
    }
    else if (x == "5")
    {
        fivead_add_money();
        again(ad_min(tk, v));
    }
    else if (x == "6")
    {
        sixad_history();
        again(ad_min(tk, v));
    }
    else if (x == "7")
    {
        sevenad_delete_history();
        again(ad_min(tk, v));
    }
}
