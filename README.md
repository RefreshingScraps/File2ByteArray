# File2ByteArray
<br>将文件转换成字节集</br>
<br>请使用Visual Studio编译。</br>
<br>使用方法：在主程序里引用生成出来的"data.h",在函数里插入以下代码：</br>
<br>	int size = sizeof(binary_bin);</br>
<br>	ofstream output_file("文件路径\文件名", ios::binary);</br>
<br>	output_file.write(reinterpret_cast<const char *>(binary_bin), size);</br>
<br>	output_file.close();</br>
