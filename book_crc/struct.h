#ifndef STRUCT_ENABLE
#define STRUCT_ENABLE 1

#ifndef WIN32_NO_STATUS
#define WIN32_NO_STATUS
#endif
#include <Windows.h>
#undef WIN32_NO_STATUS
#include <ntstatus.h>
#include <intrin.h>

#ifndef NT_SUCCESS
#define NT_SUCCESS(Status)          ((NTSTATUS)(Status) >= 0)
#endif 
#include <cstdint>
#include <vector>

#ifndef NtCurrentProcess
#define NtCurrentProcess        ((HANDLE)(LONG_PTR)-1)
#endif 

#ifndef NO_INLINE
#if defined(_MSC_VER)
#define NO_INLINE __declspec(noinline)
#elif defined(__GNUC__) && __GNUC__ > 3
#define NO_INLINE __attribute__((noinline)) 
#endif
#endif 

typedef struct _CRC_INFO
{  
	BOOLEAN crc_is_copy;  
	BOOLEAN crc_steals_check;
	uint8_t* crc_addr;
	uint8_t* crc_coped_mem;
	uint32_t crc_size;
	uint32_t crc_res;
}CRC_INFO;
 

typedef struct _CRC_INFO_FILE
{ 
	uint32_t crc_addr_rva;
	uint32_t crc_size;
	uint32_t crc_res;
}CRC_INFO_FILE;

typedef struct _CRC_FILE
{
	uint16_t crc_num;
	std::vector< CRC_INFO_FILE> crc_reg;
}CRC_FILE;

typedef struct _CRC_STATIC_INFO
{
	uint32_t crc_num;
	CRC_INFO_FILE crc_reg[100];
}CRC_STATIC_INFO;

typedef struct _CRC_FILE_INFO
{
	uint32_t crc_num;
	CRC_INFO_FILE crc_reg[2];
}CRC_FILE_INFO;

typedef struct _CRC_IGNORE_INFO
{
	uint32_t rva;
	uint32_t va;
	uint32_t size;
}CRC_IGNORE_INFO;

#endif // !STRUCT_ENABLE
