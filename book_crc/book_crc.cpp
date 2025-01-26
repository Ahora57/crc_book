#include <iostream>
#include "crc_run_sec.h"
#include "crc_disk.h"
#include "crc_static.h"
#include "crc_file.h"

int main()
{
	crc_sec::crc_sec crc_sec;
	crc_disk::crc_disk crc_disk;
	crc_file::crc_file crc_file;
	crc_static::crc_static crc_static;
	//init
	crc_sec.add_crc_module(GetModuleHandleW(NULL), FALSE, TRUE);
	
	SetConsoleTitleW(L"[CRC check]");

	while (!GetAsyncKeyState(VK_F1))
	{
		if (crc_sec.sec_check())
		{
			printf("crc runtime detect change!\n");
		}

		if (!crc_disk.is_file_valid(GetModuleHandleW(NULL)))
		{
			printf("crc disk detect change!\n");
		}


		if (!crc_file.is_file_valid(GetModuleHandleW(NULL)))
		{
			printf("crc file detect change!\n");
		}

		if (!crc_static.crc_static_check(GetModuleHandleW(NULL)))
		{
			printf("crc static detect change!\n");
		}

		Sleep(2000);
	}

	getchar();
	return FALSE;
}