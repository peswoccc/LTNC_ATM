#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <conio.h>
#include <sstream>
#include <ctime>

using namespace std;

#include "struct.h"
#include "ad_min.h"
#include "main_pro.h"
#include "check_id.h"

int main()
{
    #include "text.h"
    choose_language();
    tai_khoan tk;
    vector<tai_khoan> v = file_to_tk();
    check_id(tk, v);
    return 0;
}
