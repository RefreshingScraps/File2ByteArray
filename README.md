# File2ByteArray
<br>将文件转换成字节集</br>
<br>请使用Visual Studio编译。</br>
<br>使用方法：在主程序里引用生成出来的"data.h",在函数里插入以下代码：</br>
```
	int size = sizeof(binary_bin);
	ofstream output_file("文件路径\文件名", ios::binary);
	output_file.write(reinterpret_cast<const char *>(binary_bin), size);
	output_file.close();
```
即可生成源文件。
