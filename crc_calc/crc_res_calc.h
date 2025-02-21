#ifndef CRC_RES_CALC
#define CRC_RES_CALC 1
#include "..\book_crc\struct.h"
#include <algorithm>

#ifndef SHIFT_RELOCE
#define SHIFT_RELOCE 0xC
#endif // !SHIFT_RELOCE


namespace crc_res_calc
{
	uint32_t crc32_tab[] =
	{
		0x00000000L, 0x77073096L, 0xee0e612cL, 0x990951baL, 0x076dc419L,
		0x706af48fL, 0xe963a535L, 0x9e6495a3L, 0x0edb8832L, 0x79dcb8a4L,
		0xe0d5e91eL, 0x97d2d988L, 0x09b64c2bL, 0x7eb17cbdL, 0xe7b82d07L,
		0x90bf1d91L, 0x1db71064L, 0x6ab020f2L, 0xf3b97148L, 0x84be41deL,
		0x1adad47dL, 0x6ddde4ebL, 0xf4d4b551L, 0x83d385c7L, 0x136c9856L,
		0x646ba8c0L, 0xfd62f97aL, 0x8a65c9ecL, 0x14015c4fL, 0x63066cd9L,
		0xfa0f3d63L, 0x8d080df5L, 0x3b6e20c8L, 0x4c69105eL, 0xd56041e4L,
		0xa2677172L, 0x3c03e4d1L, 0x4b04d447L, 0xd20d85fdL, 0xa50ab56bL,
		0x35b5a8faL, 0x42b2986cL, 0xdbbbc9d6L, 0xacbcf940L, 0x32d86ce3L,
		0x45df5c75L, 0xdcd60dcfL, 0xabd13d59L, 0x26d930acL, 0x51de003aL,
		0xc8d75180L, 0xbfd06116L, 0x21b4f4b5L, 0x56b3c423L, 0xcfba9599L,
		0xb8bda50fL, 0x2802b89eL, 0x5f058808L, 0xc60cd9b2L, 0xb10be924L,
		0x2f6f7c87L, 0x58684c11L, 0xc1611dabL, 0xb6662d3dL, 0x76dc4190L,
		0x01db7106L, 0x98d220bcL, 0xefd5102aL, 0x71b18589L, 0x06b6b51fL,
		0x9fbfe4a5L, 0xe8b8d433L, 0x7807c9a2L, 0x0f00f934L, 0x9609a88eL,
		0xe10e9818L, 0x7f6a0dbbL, 0x086d3d2dL, 0x91646c97L, 0xe6635c01L,
		0x6b6b51f4L, 0x1c6c6162L, 0x856530d8L, 0xf262004eL, 0x6c0695edL,
		0x1b01a57bL, 0x8208f4c1L, 0xf50fc457L, 0x65b0d9c6L, 0x12b7e950L,
		0x8bbeb8eaL, 0xfcb9887cL, 0x62dd1ddfL, 0x15da2d49L, 0x8cd37cf3L,
		0xfbd44c65L, 0x4db26158L, 0x3ab551ceL, 0xa3bc0074L, 0xd4bb30e2L,
		0x4adfa541L, 0x3dd895d7L, 0xa4d1c46dL, 0xd3d6f4fbL, 0x4369e96aL,
		0x346ed9fcL, 0xad678846L, 0xda60b8d0L, 0x44042d73L, 0x33031de5L,
		0xaa0a4c5fL, 0xdd0d7cc9L, 0x5005713cL, 0x270241aaL, 0xbe0b1010L,
		0xc90c2086L, 0x5768b525L, 0x206f85b3L, 0xb966d409L, 0xce61e49fL,
		0x5edef90eL, 0x29d9c998L, 0xb0d09822L, 0xc7d7a8b4L, 0x59b33d17L,
		0x2eb40d81L, 0xb7bd5c3bL, 0xc0ba6cadL, 0xedb88320L, 0x9abfb3b6L,
		0x03b6e20cL, 0x74b1d29aL, 0xead54739L, 0x9dd277afL, 0x04db2615L,
		0x73dc1683L, 0xe3630b12L, 0x94643b84L, 0x0d6d6a3eL, 0x7a6a5aa8L,
		0xe40ecf0bL, 0x9309ff9dL, 0x0a00ae27L, 0x7d079eb1L, 0xf00f9344L,
		0x8708a3d2L, 0x1e01f268L, 0x6906c2feL, 0xf762575dL, 0x806567cbL,
		0x196c3671L, 0x6e6b06e7L, 0xfed41b76L, 0x89d32be0L, 0x10da7a5aL,
		0x67dd4accL, 0xf9b9df6fL, 0x8ebeeff9L, 0x17b7be43L, 0x60b08ed5L,
		0xd6d6a3e8L, 0xa1d1937eL, 0x38d8c2c4L, 0x4fdff252L, 0xd1bb67f1L,
		0xa6bc5767L, 0x3fb506ddL, 0x48b2364bL, 0xd80d2bdaL, 0xaf0a1b4cL,
		0x36034af6L, 0x41047a60L, 0xdf60efc3L, 0xa867df55L, 0x316e8eefL,
		0x4669be79L, 0xcb61b38cL, 0xbc66831aL, 0x256fd2a0L, 0x5268e236L,
		0xcc0c7795L, 0xbb0b4703L, 0x220216b9L, 0x5505262fL, 0xc5ba3bbeL,
		0xb2bd0b28L, 0x2bb45a92L, 0x5cb36a04L, 0xc2d7ffa7L, 0xb5d0cf31L,
		0x2cd99e8bL, 0x5bdeae1dL, 0x9b64c2b0L, 0xec63f226L, 0x756aa39cL,
		0x026d930aL, 0x9c0906a9L, 0xeb0e363fL, 0x72076785L, 0x05005713L,
		0x95bf4a82L, 0xe2b87a14L, 0x7bb12baeL, 0x0cb61b38L, 0x92d28e9bL,
		0xe5d5be0dL, 0x7cdcefb7L, 0x0bdbdf21L, 0x86d3d2d4L, 0xf1d4e242L,
		0x68ddb3f8L, 0x1fda836eL, 0x81be16cdL, 0xf6b9265bL, 0x6fb077e1L,
		0x18b74777L, 0x88085ae6L, 0xff0f6a70L, 0x66063bcaL, 0x11010b5cL,
		0x8f659effL, 0xf862ae69L, 0x616bffd3L, 0x166ccf45L, 0xa00ae278L,
		0xd70dd2eeL, 0x4e048354L, 0x3903b3c2L, 0xa7672661L, 0xd06016f7L,
		0x4969474dL, 0x3e6e77dbL, 0xaed16a4aL, 0xd9d65adcL, 0x40df0b66L,
		0x37d83bf0L, 0xa9bcae53L, 0xdebb9ec5L, 0x47b2cf7fL, 0x30b5ffe9L,
		0xbdbdf21cL, 0xcabac28aL, 0x53b39330L, 0x24b4a3a6L, 0xbad03605L,
		0xcdd70693L, 0x54de5729L, 0x23d967bfL, 0xb3667a2eL, 0xc4614ab8L,
		0x5d681b02L, 0x2a6f2b94L, 0xb40bbe37L, 0xc30c8ea1L, 0x5a05df1bL,
		0x2d02ef8dL
	};

	class crc_res_calc
	{
	private:
		std::vector< CRC_IGNORE_INFO> crc_ignore;
		std::vector< CRC_INFO_FILE> crc_res;

		auto malloc(size_t size) -> PVOID
		{
			return VirtualAlloc(NULL, size, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
		}

		auto free(PVOID ptr) -> VOID
		{
			if (nullptr != ptr)
				VirtualFree(ptr, NULL, MEM_RELEASE);
		}


		//https://github.com/gityf/crc/blob/ac358396a20c77cf664076c5844e656acb5978f2/crc/crc32.c#L72
		auto crc32(uint8_t* crc_addr, uint32_t crc_size) -> uint32_t
		{
			uint32_t crc_res = ~NULL;

			for (uint32_t i = NULL; i < crc_size; i++)
			{
				crc_res = crc32_tab[(crc_res ^ crc_addr[i]) & 0xFF] ^ ((crc_res >> 8) & 0x00FFFFFF);
			}

			return ~crc_res;
		}

		auto rva_to_va(uint64_t rva, PIMAGE_NT_HEADERS nt_headers, PIMAGE_SECTION_HEADER sec) -> uint64_t
		{
			for (size_t i = NULL; i < nt_headers->FileHeader.NumberOfSections; i++)
			{
				if (sec[i].VirtualAddress <= rva && (sec[i].VirtualAddress + sec[i].Misc.VirtualSize) > rva)
				{
					return rva - sec[i].VirtualAddress + sec[i].PointerToRawData;
				}
			}
			return NULL;
		}

		auto va_to_rva(uint64_t va, PIMAGE_NT_HEADERS nt_headers, PIMAGE_SECTION_HEADER sec) -> uint64_t
		{
			for (size_t i = NULL; i < nt_headers->FileHeader.NumberOfSections; i++)
			{
				if (sec[i].PointerToRawData <= va && (sec[i].PointerToRawData + sec[i].SizeOfRawData) > va)
				{
					return va - sec[i].PointerToRawData + sec[i].VirtualAddress;
				}
			}
			return NULL;
		}


		auto scan_pattern_crc_static(PVOID addr_file, uint8_t** addr_pattern) -> BOOLEAN
		{
			uint32_t pattern[] = { 0xDEADC0DE, 0xBEEF,0X1,0XDEADC0DE };
			uint8_t* cur_addr_sec = NULL;
			PIMAGE_NT_HEADERS nt_headers = NULL;
			PIMAGE_SECTION_HEADER sec = NULL;
			nt_headers = reinterpret_cast<PIMAGE_NT_HEADERS>(reinterpret_cast<CHAR*>(addr_file) + reinterpret_cast<IMAGE_DOS_HEADER*>(addr_file)->e_lfanew);
			if (nt_headers->Signature != IMAGE_NT_SIGNATURE)
				return FALSE;

			sec = IMAGE_FIRST_SECTION(nt_headers);

			for (size_t i = NULL; i < nt_headers->FileHeader.NumberOfSections; i++)
			{
				if ((sec[i].Characteristics & IMAGE_SCN_MEM_READ) && (sec[i].Characteristics & IMAGE_SCN_MEM_WRITE) && sec[i].SizeOfRawData > sizeof(CRC_STATIC_INFO))
				{
					for (size_t j = NULL; j < sec[i].SizeOfRawData - sizeof(CRC_STATIC_INFO); j++)
					{
						cur_addr_sec = reinterpret_cast<uint8_t*>(addr_file) + sec[i].PointerToRawData + j;
						if (!memcmp(cur_addr_sec, &pattern[NULL], sizeof(pattern)))
						{ 
							*addr_pattern = cur_addr_sec;
							return TRUE;
						}
					}
				}

			}
			return FALSE;
		}

		auto scan_pattern_crc_file(PVOID addr_file, uint8_t** addr_pattern) -> BOOLEAN
		{
			uint32_t pattern[] = { 0xBEEF,0X2,0XDEADC0DE };
			uint8_t* cur_addr_sec = NULL;
			PIMAGE_NT_HEADERS nt_headers = NULL;
			PIMAGE_SECTION_HEADER sec = NULL;
			nt_headers = reinterpret_cast<PIMAGE_NT_HEADERS>(reinterpret_cast<CHAR*>(addr_file) + reinterpret_cast<IMAGE_DOS_HEADER*>(addr_file)->e_lfanew);
			if (nt_headers->Signature != IMAGE_NT_SIGNATURE)
				return FALSE;

			sec = IMAGE_FIRST_SECTION(nt_headers);

			for (size_t i = NULL; i < nt_headers->FileHeader.NumberOfSections; i++)
			{
				if ((sec[i].Characteristics & IMAGE_SCN_MEM_READ) && (sec[i].Characteristics & IMAGE_SCN_MEM_WRITE) && sec[i].SizeOfRawData > sizeof(pattern))
				{
					for (size_t j = NULL; j < sec[i].SizeOfRawData - sizeof(pattern); j++)
					{
						cur_addr_sec = reinterpret_cast<uint8_t*>(addr_file) + sec[i].PointerToRawData + j;
						if (!memcmp(cur_addr_sec, &pattern[NULL], sizeof(pattern)))
						{ 
							*addr_pattern = cur_addr_sec;
							return TRUE;
						}
					}
				}

			}
			return FALSE;
		}
		auto disk_calc_file_crc(PVOID addr_file,uint32_t size_file, uint8_t* addr_pattern) -> BOOLEAN
		{
			PIMAGE_NT_HEADERS nt_headers = NULL;
			PIMAGE_SECTION_HEADER sec = NULL;
			CRC_FILE_INFO crc_file_info = {NULL};

			nt_headers = reinterpret_cast<PIMAGE_NT_HEADERS>(reinterpret_cast<CHAR*>(addr_file) + reinterpret_cast<IMAGE_DOS_HEADER*>(addr_file)->e_lfanew);
			if (nt_headers->Signature != IMAGE_NT_SIGNATURE)
				return FALSE;

			sec = IMAGE_FIRST_SECTION(nt_headers);
			 
		 
			if (addr_pattern - addr_file == nt_headers->OptionalHeader.SizeOfHeaders)//skip pe and next start sec - pattern
			{
				crc_file_info.crc_reg[NULL].crc_addr_rva = nt_headers->OptionalHeader.SizeOfHeaders + sizeof(crc_file_info);
				crc_file_info.crc_reg[NULL].crc_size = size_file - nt_headers->OptionalHeader.SizeOfHeaders - sizeof(crc_file_info);
				crc_file_info.crc_reg[NULL].crc_res = crc32(reinterpret_cast<uint8_t*>(addr_file) + crc_file_info.crc_reg[NULL].crc_addr_rva, crc_file_info.crc_reg[NULL].crc_size);
				
				crc_file_info.crc_num = 1; 
			} 
			else
			{ 
				crc_file_info.crc_reg[NULL].crc_addr_rva = nt_headers->OptionalHeader.SizeOfHeaders;
				crc_file_info.crc_reg[NULL].crc_size = (addr_pattern - addr_file) - nt_headers->OptionalHeader.SizeOfHeaders;
				crc_file_info.crc_reg[NULL].crc_res = crc32(reinterpret_cast<uint8_t*>(addr_file) + crc_file_info.crc_reg[NULL].crc_addr_rva, crc_file_info.crc_reg[NULL].crc_size);

				crc_file_info.crc_reg[1].crc_addr_rva = (addr_pattern - addr_file)  + sizeof(crc_file_info);
				crc_file_info.crc_reg[1].crc_size = size_file - (addr_pattern - addr_file)  - sizeof(crc_file_info);
				crc_file_info.crc_reg[1].crc_res = crc32(reinterpret_cast<uint8_t*>(addr_file) + crc_file_info.crc_reg[1].crc_addr_rva, crc_file_info.crc_reg[1].crc_size);

				crc_file_info.crc_num = 2;
			}

			reinterpret_cast<CRC_FILE_INFO*>(addr_pattern)->crc_num = crc_file_info.crc_num;

			addr_pattern += sizeof(uint32_t);

			for (size_t i = 0; i < crc_file_info.crc_num; i++)
			{
				reinterpret_cast<CRC_INFO_FILE*>(addr_pattern)->crc_addr_rva = crc_file_info.crc_reg[i].crc_addr_rva;
				reinterpret_cast<CRC_INFO_FILE*>(addr_pattern)->crc_size = crc_file_info.crc_reg[i].crc_size; 
				reinterpret_cast<CRC_INFO_FILE*>(addr_pattern)->crc_res = crc_file_info.crc_reg[i].crc_res;

				addr_pattern += sizeof(CRC_INFO_FILE);
			} 
			return TRUE;
 			  
		}




		auto disk_calc_static_crc(PVOID addr_file, uint8_t* addr_pattern) -> BOOLEAN
		{
			BOOLEAN fisrt_crc_init = FALSE;
			BOOLEAN ignore_first_sec_byte = FALSE;
			BOOLEAN any_crc_ignore = FALSE;
			uint32_t end_reloce = NULL;

			CHAR* name_imp_dll = NULL;
			uint16_t* relative_info = NULL;
			uint64_t* orig_first_thunk = NULL;
			uint64_t* first_thunk = NULL;

			PIMAGE_NT_HEADERS nt_headers = NULL;
			PIMAGE_BASE_RELOCATION va_reloce = NULL;
			PIMAGE_BASE_RELOCATION size_reloce = NULL;
			PIMAGE_SECTION_HEADER sec = NULL;
			PIMAGE_IMPORT_DESCRIPTOR imp_descript = NULL;
			PIMAGE_IMPORT_BY_NAME import_name = NULL;
			CRC_IGNORE_INFO crc_cur_ignore = { NULL };
			CRC_INFO_FILE crc_cur_file = { NULL };
			nt_headers = reinterpret_cast<PIMAGE_NT_HEADERS>(reinterpret_cast<CHAR*>(addr_file) + reinterpret_cast<IMAGE_DOS_HEADER*>(addr_file)->e_lfanew);
			if (nt_headers->Signature != IMAGE_NT_SIGNATURE)
				return FALSE;

			sec = IMAGE_FIRST_SECTION(nt_headers);

			if (nt_headers->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_BASERELOC].Size)
			{
				va_reloce = reinterpret_cast<PIMAGE_BASE_RELOCATION>(reinterpret_cast<uint8_t*>(addr_file) + rva_to_va(nt_headers->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_BASERELOC].VirtualAddress, nt_headers, sec));
				size_reloce = reinterpret_cast<PIMAGE_BASE_RELOCATION>(reinterpret_cast<uintptr_t>(va_reloce) + nt_headers->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_BASERELOC].Size);

				while (va_reloce < size_reloce && va_reloce->SizeOfBlock)
				{
					end_reloce = (va_reloce->SizeOfBlock - sizeof(IMAGE_BASE_RELOCATION)) / sizeof(WORD);
					relative_info = reinterpret_cast<uint16_t*>(va_reloce + 1);

					for (uint32_t i = NULL; i != end_reloce; ++i, ++relative_info)
					{
						switch ((*relative_info) >> SHIFT_RELOCE)//https://github.com/DarthTon/Blackbone/blob/5ede6ce50cd8ad34178bfa6cae05768ff6b3859b/src/BlackBoneDrv/ldrreloc.c#L252
						{
						case IMAGE_REL_BASED_DIR64:
						{
							crc_cur_ignore.size = sizeof(uint64_t);
							crc_cur_ignore.rva = va_reloce->VirtualAddress + ((*relative_info) & 0xFFF);
							crc_cur_ignore.va = rva_to_va(crc_cur_ignore.rva, nt_headers, sec);
							crc_ignore.push_back(crc_cur_ignore);
							break;
						}
						case IMAGE_REL_BASED_HIGHLOW:
						{
							crc_cur_ignore.size = sizeof(uint32_t);
							crc_cur_ignore.rva = va_reloce->VirtualAddress + ((*relative_info) & 0xFFF);
							crc_cur_ignore.va = rva_to_va(crc_cur_ignore.rva, nt_headers, sec);
							crc_ignore.push_back(crc_cur_ignore);
							break;
						}
						case IMAGE_REL_BASED_LOW:
						{
							crc_cur_ignore.size = sizeof(uint16_t);
							crc_cur_ignore.rva = va_reloce->VirtualAddress + ((*relative_info) & 0xFFF);
							crc_cur_ignore.va = rva_to_va(crc_cur_ignore.rva, nt_headers, sec);
							crc_ignore.push_back(crc_cur_ignore);
							break;
						}
						case IMAGE_REL_BASED_ABSOLUTE:
						{
							break;
						}
						default:
						{
							return FALSE;
							break;
						}
						}

					}
					va_reloce = reinterpret_cast<PIMAGE_BASE_RELOCATION>(reinterpret_cast<BYTE*>(va_reloce) + va_reloce->SizeOfBlock);
				}
			}

			if (nt_headers->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].Size)
			{
				imp_descript = reinterpret_cast<PIMAGE_IMPORT_DESCRIPTOR>(reinterpret_cast<CHAR*>(addr_file) + rva_to_va(nt_headers->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress, nt_headers, sec));
				for (; imp_descript->Name; ++imp_descript)
				{
					name_imp_dll = reinterpret_cast<CHAR*>(addr_file) + rva_to_va(imp_descript->Name, nt_headers, sec);
					if (name_imp_dll)
					{

						orig_first_thunk = reinterpret_cast<uint64_t*>(reinterpret_cast<CHAR*>(addr_file) + rva_to_va(imp_descript->OriginalFirstThunk, nt_headers, sec));
						first_thunk = reinterpret_cast<uint64_t*>(reinterpret_cast<CHAR*>(addr_file) + rva_to_va(imp_descript->FirstThunk, nt_headers, sec));

						if (!orig_first_thunk) //load by index https://stackoverflow.com/questions/42413937/why-pe-need-original-first-thunkoft
						{
							orig_first_thunk = first_thunk;
						}

						for (; *orig_first_thunk; orig_first_thunk++, first_thunk++)
						{

							crc_cur_ignore.size = sizeof(PVOID);
							crc_cur_ignore.rva = va_to_rva(reinterpret_cast<uint8_t*>(first_thunk) - addr_file, nt_headers, sec);;
							crc_cur_ignore.va = reinterpret_cast<uint8_t*>(first_thunk) - addr_file;

							crc_ignore.push_back(crc_cur_ignore);

						}

					}
				}

			}

			std::sort(crc_ignore.begin(), crc_ignore.end(), [](CRC_IGNORE_INFO& cur, CRC_IGNORE_INFO& next){return cur.rva < next.rva; });
			//printf("ignore number ->\t%d\n", crc_ignore.size());

			//for (size_t i = NULL; i < crc_ignore.size(); i++)
			//{
			//	printf("ignore rva ->\t%x\n", crc_ignore[i].rva);
			//	printf("ignore va ->\t%x\n", crc_ignore[i].va);
			//	printf("ignore size ->\t%x\n", crc_ignore[i].size);
			//}

			for (size_t i = NULL; i < nt_headers->FileHeader.NumberOfSections; i++)
			{
				fisrt_crc_init = FALSE;
				if ((sec[i].Characteristics & IMAGE_SCN_MEM_READ) && !(sec[i].Characteristics & IMAGE_SCN_MEM_WRITE) && sec[i].SizeOfRawData > sizeof(PVOID))
				{
					any_crc_ignore = TRUE;
					for (size_t j = NULL; j < crc_ignore.size(); j++)
					{
						if (crc_ignore[j].rva >= sec[i].VirtualAddress && (sec[i].VirtualAddress + sec[i].Misc.VirtualSize - sizeof(PVOID)) > crc_ignore[j].rva)
						{
							any_crc_ignore = FALSE;
							break;
						}
					}

					if (any_crc_ignore)	//crc res all secthion
					{
						crc_cur_file.crc_addr_rva = sec[i].VirtualAddress;
						crc_cur_file.crc_size = sec[i].SizeOfRawData;
						crc_cur_file.crc_res = crc32(reinterpret_cast<uint8_t*>(addr_file) + rva_to_va(crc_cur_file.crc_addr_rva, nt_headers, sec), crc_cur_file.crc_size);

						crc_res.push_back(crc_cur_file);

					}
					else //get crc
					{
						fisrt_crc_init = TRUE;

						for (size_t j = NULL; j < crc_ignore.size(); j++)
						{
							if (crc_ignore[j].rva >= sec[i].VirtualAddress && (sec[i].VirtualAddress + sec[i].Misc.VirtualSize - sizeof(PVOID)) > crc_ignore[j].rva)
							{
								ignore_first_sec_byte = FALSE;
								if (crc_ignore[j].rva == sec[i].VirtualAddress)
								{
									ignore_first_sec_byte = TRUE;
								}

								if (!ignore_first_sec_byte)
								{
									if (fisrt_crc_init)
									{


										if (j == NULL && crc_ignore[j].rva - sec[i].VirtualAddress > NULL)
										{
											if (crc_ignore.size() > j && crc_ignore[j + 1].rva - crc_ignore[j].rva > NULL)
											{ 
												crc_cur_file.crc_addr_rva = sec[i].VirtualAddress;
												crc_cur_file.crc_size = crc_ignore[j].rva - sec[i].VirtualAddress;
												crc_cur_file.crc_res = crc32(reinterpret_cast<uint8_t*>(addr_file) + rva_to_va(crc_cur_file.crc_addr_rva, nt_headers, sec), crc_cur_file.crc_size);
												crc_res.push_back(crc_cur_file);

												fisrt_crc_init = FALSE;

											}
										}
										else
										{
											if (crc_ignore.size() > j && crc_ignore[j + 1].rva - (crc_ignore[j].rva + crc_ignore[j].size) > NULL)
											{
												if (crc_ignore[j + 1].rva >= sec[i].VirtualAddress && (sec[i].VirtualAddress + sec[i].Misc.VirtualSize) > crc_ignore[j + 1].rva)
												{
													crc_cur_file.crc_addr_rva = crc_ignore[j].rva + crc_ignore[j].size;
													crc_cur_file.crc_size = crc_ignore[j + 1].rva - crc_cur_file.crc_addr_rva;
													crc_cur_file.crc_res = crc32(reinterpret_cast<uint8_t*>(addr_file) + rva_to_va(crc_cur_file.crc_addr_rva, nt_headers, sec), crc_cur_file.crc_size);
													fisrt_crc_init = FALSE;
													crc_res.push_back(crc_cur_file);
												}
												else
												{
													break;
												}

											}
											else if (crc_ignore.size() == 1)
											{
												 
												//not check code
												crc_cur_file.crc_addr_rva = sec[i].VirtualAddress;
												crc_cur_file.crc_size = crc_ignore[j].rva - crc_cur_file.crc_addr_rva;
												crc_cur_file.crc_res = crc32(reinterpret_cast<uint8_t*>(addr_file) + rva_to_va(crc_cur_file.crc_addr_rva, nt_headers, sec), crc_cur_file.crc_size);
												crc_res.push_back(crc_cur_file);

												//not check code
												crc_cur_file.crc_addr_rva = crc_ignore[j].rva + crc_ignore[j].size;
												crc_cur_file.crc_size = sec[i].SizeOfRawData - crc_cur_file.crc_addr_rva;
												crc_cur_file.crc_res = crc32(reinterpret_cast<uint8_t*>(addr_file) + rva_to_va(crc_cur_file.crc_addr_rva, nt_headers, sec), crc_cur_file.crc_size);
												crc_res.push_back(crc_cur_file);
												fisrt_crc_init = FALSE;
											}

										}
									}
									else
									{
										if (crc_ignore.size() > j)
										{
											if (crc_ignore[j + 1].rva - (crc_ignore[j].rva + crc_ignore[j].size) > NULL)
											{
												if (crc_ignore[j + 1].rva >= sec[i].VirtualAddress && (sec[i].VirtualAddress + sec[i].Misc.VirtualSize) > crc_ignore[j + 1].rva + crc_ignore[j + 1].size)
												{
													if (crc_ignore[j + 1].rva > crc_ignore[j].rva && crc_ignore[j + 1].rva > crc_ignore[j].rva + crc_ignore[j].size)
													{
														crc_cur_file.crc_addr_rva = crc_ignore[j].rva + crc_ignore[j].size;
														crc_cur_file.crc_size = crc_ignore[j + 1].rva - crc_cur_file.crc_addr_rva;
														crc_cur_file.crc_res = crc32(reinterpret_cast<uint8_t*>(addr_file) + rva_to_va(crc_cur_file.crc_addr_rva, nt_headers, sec), crc_cur_file.crc_size);
														fisrt_crc_init = FALSE;

														crc_res.push_back(crc_cur_file);
													}
												}
												else  if (sec[i].VirtualAddress + sec[i].SizeOfRawData - (crc_ignore[j].rva + crc_ignore[j].size) > NULL)
												{
													crc_cur_file.crc_addr_rva = crc_ignore[j].rva + crc_ignore[j].size;
													crc_cur_file.crc_size = sec[i].VirtualAddress + sec[i].SizeOfRawData - crc_cur_file.crc_addr_rva;
													crc_cur_file.crc_res = crc32(reinterpret_cast<uint8_t*>(addr_file) + rva_to_va(crc_cur_file.crc_addr_rva, nt_headers, sec), crc_cur_file.crc_size);
													fisrt_crc_init = FALSE;

													crc_res.push_back(crc_cur_file);
													break;
												}
												else
												{
													break;
												}
											}
										}
										else if (crc_ignore.size() == 1)
										{
											__debugbreak();
										}
									}
								}
								else//start by cur and next rva
								{
									if (crc_ignore.size() > j)
									{
										if (crc_ignore[j + 1].rva - (crc_ignore[j].rva + crc_ignore[j].size) > NULL)
										{
											if (crc_ignore[j + 1].rva > crc_ignore[j].rva && crc_ignore[j + 1].rva > crc_ignore[j].rva + crc_ignore[j].size)
											{
												crc_cur_file.crc_addr_rva = crc_ignore[j].rva + crc_ignore[j].size;
												crc_cur_file.crc_size = crc_ignore[j + 1].rva - crc_cur_file.crc_addr_rva;
												crc_cur_file.crc_res = crc32(reinterpret_cast<uint8_t*>(addr_file) + rva_to_va(crc_cur_file.crc_addr_rva, nt_headers, sec), crc_cur_file.crc_size);

												crc_res.push_back(crc_cur_file);
											}
										}
									}
									else if (crc_ignore.size() == 1)
									{

										//not check code
										crc_cur_file.crc_addr_rva = crc_ignore[j].rva + crc_ignore[j].size;
										crc_cur_file.crc_size = sec[i].VirtualAddress + sec[i].SizeOfRawData - crc_ignore[j].size;
										crc_cur_file.crc_res = crc32(reinterpret_cast<uint8_t*>(addr_file) + rva_to_va(crc_cur_file.crc_addr_rva, nt_headers, sec), crc_cur_file.crc_size);
										crc_res.push_back(crc_cur_file);
										fisrt_crc_init = FALSE;

									}
								}
							}
						}

					}
				}
			}


			//printf("crc num ->\t%p\n", crc_res.size());
			//
			//
			//for (size_t i = NULL; i < crc_res.size(); i++)
			//{
			//
			//
			//	printf("crc rva ->\t%p\n", crc_res[i].crc_addr_rva);
			//	printf("crc va ->\t%p\n", nt_headers->OptionalHeader.ImageBase + crc_res[i].crc_addr_rva);
			//	printf("crc size ->\t%p\n", crc_res[i].crc_size);
			//	printf("crc res ->\t%p\n", crc_res[i].crc_res);
			//
			//}

			//copy size
			reinterpret_cast<CRC_STATIC_INFO*>(addr_pattern)->crc_num = crc_res.size();
			addr_pattern += sizeof(uint32_t);

			for (size_t i = NULL; i < crc_res.size(); i++)
			{
				reinterpret_cast<CRC_INFO_FILE*>(addr_pattern)->crc_addr_rva = crc_res[i].crc_addr_rva;
				reinterpret_cast<CRC_INFO_FILE*>(addr_pattern)->crc_res = crc_res[i].crc_res;
				reinterpret_cast<CRC_INFO_FILE*>(addr_pattern)->crc_size = crc_res[i].crc_size;
				addr_pattern += sizeof(CRC_INFO_FILE);
			}


			//copy crc data
			return TRUE;
		}

	public:


		auto  get_crc_list(CONST WCHAR* file_path, BOOLEAN static_crc,BOOLEAN file_crc) -> BOOLEAN
		{
			BOOLEAN is_create = FALSE;
			uint32_t old_size_file = NULL;
			DWORD num_read = NULL;
			uint8_t* pattern_addr = NULL;
			PVOID memory_module = NULL;
			PVOID memory_file = NULL;
			HANDLE access_file = NULL;
			HANDLE new_access = NULL;
			std::wstring new_file = L"";

			access_file = CreateFileW(file_path, GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

			if (access_file != INVALID_HANDLE_VALUE)
			{
				old_size_file = GetFileSize(access_file, NULL);
				if (old_size_file)
				{
					memory_file = malloc(old_size_file);
					if (memory_file)
					{
						memset(memory_file, NULL, old_size_file);
						if (ReadFile(access_file, memory_file, old_size_file, &num_read, NULL))
						{
							if (static_crc && scan_pattern_crc_static(memory_file, &pattern_addr))
							{
								is_create = disk_calc_static_crc(memory_file, pattern_addr);
							}

							if (is_create && file_crc && scan_pattern_crc_file(memory_file, &pattern_addr))
							{
								is_create = disk_calc_file_crc(memory_file, old_size_file, pattern_addr);

							}

							new_file = file_path;
							new_file += L"_new.exe";

							new_access = CreateFileW
							(
								new_file.c_str(),
								GENERIC_READ | GENERIC_WRITE,
								NULL,
								NULL,
								CREATE_ALWAYS,
								FILE_ATTRIBUTE_NORMAL,
								NULL
							);
							if (new_access)
							{
								if (WriteFile(new_access, memory_file, old_size_file, NULL, NULL))
								{
									printf("success!\n");
									is_create = TRUE;
								}
								CloseHandle(new_access);
							}
						}
						free(memory_file);
					}
				}
				CloseHandle(access_file);

			}
			crc_ignore.clear();
			return is_create;

		}

	};

}
#endif // !CRC_RES_CALC
