#include <iostream>
#include <cctype>

static void megaphone(const char *s) {
	if(!s) return;
    for (std::size_t i = 0; s[i]; ++i)
        std::cout << static_cast<char>(std::toupper(static_cast<unsigned char>(s[i])));
}

int main(int argc, char *argv[]) {
	if(argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for(int i = 1; i < argc; ++i)
			megaphone(argv[i]);
		std::cout  << std::endl;
	}
	return 0;
}


//std::cout << "line1" << std::endl; 改行 + flash = 頻繁に使うと遅くなる
//std::cout << "line1\n"; 			 改行のみでflashは行わない = 大量出力ではこちらのほうがいい
