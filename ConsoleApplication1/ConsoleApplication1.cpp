#include <filesystem>
#include <fstream>
#include <intrin.h>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <windows.h>
using namespace std;
int main() {
	string sourceFileName;
	cin >> sourceFileName;
	filesystem::path filePath(sourceFileName);
	string destinationFileName = "data.h";
	//打开源文件
	ifstream sourceFile(sourceFileName, ios::binary);
	if (!sourceFile) {
		cout << "打开文件失败!" << endl;
		return -1;
	}
	//获取文件大小
	sourceFile.seekg(0, ios::end);
	streampos fileSize = sourceFile.tellg();
	sourceFile.seekg(0, ios::beg);
	// 创建存储文件内容的字节数组 
	vector<unsigned char> byteArray(fileSize);
	//读取源文件内容到字节数组 
	sourceFile.read(reinterpret_cast<char*>(byteArray.data()), fileSize);
	sourceFile.close();

	std::ofstream destinationFile(destinationFileName);
	if (destinationFile) {
		destinationFile << "#ifndef BINARY_DATA_H\n#define BINARY_DATA_H\nconst unsigned char binary_bin[] = {\n\t";
		for (const auto& byte : byteArray) {
			destinationFile << "0x" << setw(2) << setfill('0') << hex << static_cast<int>(byte) << ",";
		}
		destinationFile.seekp(-6, ios::end);
		destinationFile << " ";
		destinationFile << "\n};\nconst unsigned int binaryDatasize = sizeof(binary_bin);\n#endif";
		destinationFile.close();
		cout << "转换成功!" << endl;
		return 1;
	}
	else {
		cout << "保存文件失败!" << endl;
		return 0;
	}
}
// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
