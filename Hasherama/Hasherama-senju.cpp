
#include <Windows.h>
#include <stdio.h>


// reference: https://github.com/vxunderground/VX-API/blob/main/VX-API/HashStringJenkinsOneAtATime32Bit.cpp

#define INITIAL_SEED	7	// recommended to be 0 < INITIAL_SEED < 10

// generate Djb2A hashes from Ascii input string

DWORD HashStringDjb2A(_In_ LPCSTR String)
{
	ULONG Hash = 5381;
	INT c = 0;

	while (c = *String++)
		Hash = ((Hash << 5) + Hash) + c;

	return Hash;
}
// generate Djb2A hashes from wide-character input string

DWORD HashStringDjb2W(_In_ LPCWSTR String)
{
	ULONG Hash = 5381;
	INT c = 0;

	while (c = *String++)
		Hash = ((Hash << 5) + Hash) + c;

	return Hash;
}

// generate FowlerNollVoVariant1a hashes from Ascii input string


ULONG HashStringFowlerNollVoVariant1aA(_In_ LPCSTR String)
{
	ULONG Hash = 0x811c9dc5;

	while (*String)
	{
		Hash ^= (UCHAR)*String++;
		Hash *= 0x01000193;
	}

	return Hash;
}


// generate FowlerNollVoVariant1a hashes from wide-chars input string

ULONG HashStringFowlerNollVoVariant1aW(_In_ LPCWSTR String)
{
	ULONG Hash = 0x811c9dc5;

	while (*String)
	{
		Hash ^= (UCHAR)*String++;
		Hash *= 0x01000193;
	}

	return Hash;
}


// generate LoseLose hashes from Ascii input string


DWORD HashStringLoseLoseA(_In_ LPCSTR String)
{
	ULONG Hash = 0;
	INT c;

	while (c = *String++)
		Hash += c;

	return Hash;
}

// generate LoseLose hashes from wide-chars input string


DWORD HashStringLoseLoseW(_In_ LPCWSTR String)
{
	ULONG Hash = 0;
	INT c;

	while (c = *String++)
		Hash += c;

	return Hash;
}


// generate Sdbm hashes from Ascii input string


DWORD HashStringSdbmA(_In_ LPCSTR String)
{
	ULONG Hash = 0;
	INT c;

	while (c = *String++)
		Hash = c + (Hash << 6) + (Hash << 16) - Hash;

	return Hash;
}

// generate Sdbm hashes from Wide input string


DWORD HashStringSdbmW(_In_ LPCWSTR String)
{
	ULONG Hash = 0;
	INT c;

	while (c = *String++)
		Hash = c + (Hash << 6) + (Hash << 16) - Hash;

	return Hash;
}



// generate UnknownGenericHash1A hashes from Ascii input string


INT HashStringUnknownGenericHash1A(_In_ LPCSTR String)
{
	PCHAR Pointer;
	INT Generic;
	INT Hash = 0;

	for (Pointer = (PCHAR)String; *Pointer != '\0'; Pointer++)
	{
		Hash = (Hash << 4) + (INT)(*Pointer);
		Generic = Hash & 0xF0000000L;

		if (Generic != 0)
			Hash = Hash ^ (Generic >> 24);

		Hash = Hash & ~Generic;
	}

	return Hash;
}


// generate UnknownGenericHash1A hashes from wide-chars input string

INT HashStringUnknownGenericHash1W(_In_ LPCWSTR String)
{
	PWCHAR Pointer;
	INT Generic;
	INT Hash = 0;

	for (Pointer = (PWCHAR)String; *Pointer != '\0'; Pointer++)
	{
		Hash = (Hash << 4) + (INT)(*Pointer);
		Generic = Hash & 0xF0000000L;

		if (Generic != 0)
			Hash = Hash ^ (Generic >> 24);

		Hash = Hash & ~Generic;
	}

	return Hash;
}




// generate JenkinsOneAtATime32Bit hashes from Ascii input string
UINT32 HashStringJenkinsOneAtATime32BitA(_In_ PCHAR String)
{
	SIZE_T Index = 0;
	UINT32 Hash = 0;
	SIZE_T Length = lstrlenA(String);

	while (Index != Length)
	{
		Hash += String[Index++];
		Hash += Hash << INITIAL_SEED;
		Hash ^= Hash >> 6;
	}

	Hash += Hash << 3;
	Hash ^= Hash >> 11;
	Hash += Hash << 15;

	return Hash;
}

// generate JenkinsOneAtATime32Bit hashes from wide-character input string
UINT32 HashStringJenkinsOneAtATime32BitW(_In_ PWCHAR String)
{
	SIZE_T Index = 0;
	UINT32 Hash = 0;
	SIZE_T Length = lstrlenW(String);

	while (Index != Length)
	{
		Hash += String[Index++];
		Hash += Hash << INITIAL_SEED;
		Hash ^= Hash >> 6;
	}

	Hash += Hash << 3;
	Hash ^= Hash >> 11;
	Hash += Hash << 15;

	return Hash;
}




int main() {

	LPCSTR	cTest	= "ElB1gR0m4";
	LPCWSTR	wTest	= L"ElB1gR0m4";

	printf("[+] Hash Of \"%s\" Is : 0x%0.8X \n", cTest, HashStringJenkinsOneAtATime32BitA(cTest));
	wprintf(L"[+] Hash Of \"%s\" Is : 0x%0.8X \n", wTest, HashStringJenkinsOneAtATime32BitW(wTest));

	printf("[#] Press <Enter> To Quit ... ");
	getchar();

	return 0;
}



