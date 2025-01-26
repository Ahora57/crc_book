#include <iostream>
#include  "crc_res_calc.h"

int main()
{
    crc_res_calc::crc_res_calc crc_get;

   crc_get.get_crc_list(L"D:\\book_crc.exe",TRUE,TRUE);
   getchar();
}
