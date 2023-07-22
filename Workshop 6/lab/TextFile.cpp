#include <iostream>
#include <fstream>
#include <string>
#include "TextFile.h"
#include "cstring.h"

using namespace std;
namespace sdds {
	Line::Line() {
		m_value = nullptr;
	}

	Line::operator const char* () const {
		return (const char*)m_value;
	}
	Line& Line::operator=(const char* lineValue) {
		delete[] m_value;
		m_value = new char[strLen(lineValue) + 1];
		strCpy(m_value, lineValue);
		return *this;
	}
	Line::~Line() {
		delete[] m_value;
		m_value = nullptr;
	}

	void TextFile::setEmpty() {
		delete[] m_textLines;
		m_textLines = nullptr;
		delete[] m_filename;
		m_filename = nullptr;
		m_noOfLines = 0;
	}

	void TextFile::setFilename(const char* fname, bool isCopy) {
		if (!isCopy) {
			delete[] m_filename;
			m_filename = nullptr;
			m_filename = new char[strLen(fname) + 1];
			strCpy(m_filename, fname);
		}
		else {
			delete[] m_filename;
			m_filename = nullptr;
			const char* prefix = "C_";
			m_filename = new char[strLen(fname) + 3];
			m_filename[0] = '\0';
			strCat(m_filename, prefix);
			strCat(m_filename, fname);
		}
	}

	void TextFile::setNoOfLines() {
		ifstream file(m_filename);
		char ch;
		m_noOfLines = 0;

		if (file) {
			while (file.get(ch)) {
				if (ch == '\n') {
					m_noOfLines++;
				}
			}
			file.close();
		}

		if (m_noOfLines == 0) {
			delete[] m_filename;
			m_filename = nullptr;
		}
		m_noOfLines++;
	}

	void TextFile::loadText() {

		if (!(m_filename == nullptr)) {
			int i = 0;

			delete[] m_textLines;
			m_textLines = nullptr;
			m_textLines = new Line[m_noOfLines];

			ifstream file(m_filename);

			if (file) {
				string line;
				while (getLine(file, line)) {
					m_textLines[i] = line.c_str();
					i++;
				}
				m_noOfLines = i;
				file.close();
			}
		}
	}

	bool TextFile::getLine(ifstream& read, std::string& line) {
		if (read.is_open()) {
			char ch;
			line = "";
			while (read.get(ch)) {
				if (ch == '\n') {
					break;
				}
				line += ch;
				
			}
			return !line.empty() || !read.eof();
			
		}
		return false;
		
	}

	void TextFile::saveAs(const char* fileName)const {
		ofstream file(fileName);



		if (file) {
			for (int i = 0; i < int(m_noOfLines); i++) {
				file << m_textLines[i] << '\n';
			}
			file.close();
		}

	}

	TextFile::TextFile(unsigned pageSize) {
		m_pageSize = pageSize;
		m_textLines = nullptr;
		m_filename = nullptr;
		m_noOfLines = 0;
	}

	TextFile::TextFile(const char* filename, unsigned pageSize) {
		m_pageSize = pageSize;
		m_textLines = nullptr;
		m_filename = nullptr;
		m_noOfLines = 0;

		if (filename != nullptr) {
			m_filename = new char[strLen(filename) + 1];
			strCpy(m_filename, filename);
			setNoOfLines();
			loadText();
		}
	}

	TextFile::TextFile(const TextFile& src) {
		m_pageSize = src.m_pageSize;
		m_filename = nullptr;
		m_noOfLines = src.m_noOfLines;
		m_textLines = nullptr;

		if (src) {
			setFilename(src.m_filename, true);
			m_textLines = new Line[src.m_noOfLines];
			for (int i = 0; i < int(src.m_noOfLines); i++) {
				m_textLines[i] = src.m_textLines[i].m_value;
			}
			saveAs(m_filename);
			loadText();
		}
		else {
			m_textLines = nullptr;

		}
	}

	TextFile& TextFile::operator=(const TextFile& src) {
		if (this != &src) {
			if (*this && src) {
				delete[] m_textLines;
				m_textLines = nullptr;
				m_noOfLines = src.m_noOfLines;
				m_pageSize = src.m_pageSize;
				m_textLines = new Line[m_noOfLines];

				for (int i = 0; i < int(m_noOfLines); i++) {
					m_textLines[i] = src.m_textLines[i].m_value;
				}
				saveAs(m_filename);
				loadText();

			}
			else {
				m_textLines = nullptr;
			}
		}
		return *this;
	}

	TextFile::~TextFile() {
		delete[] m_textLines;
		m_textLines = nullptr;
		delete[] m_filename;
		m_filename = nullptr;
	}

	unsigned TextFile::lines()const {
		return m_noOfLines;
	}

	TextFile::operator bool()const {
		if (m_textLines != nullptr && m_filename != nullptr && m_noOfLines != 0) {
			return true;
		}
		return false;
	}

	const char* TextFile::name()const {
		return (const char*)m_filename;
	}

	std::ostream& TextFile::view(std::ostream& ostr)const {
		if (*this) {
			ostr << m_filename << endl;
			for (int i = 0; i < strLen(m_filename); i++) {
				ostr << "=";
			}
			ostr << endl;
			int temp = 0;
			for (int i = 0; i < int(m_noOfLines); i++) {
				
				ostr << m_textLines[i].m_value << endl;
				if ((i+1) % m_pageSize == 0) {
					ostr << "Hit ENTER to continue...";
					ostr.flush();
					if (temp == 0) {
						cin.ignore(256, '\n');
						cin.get();
						temp++;
					}
					else {
						cin.ignore(256, '\n');
					}
				}
				
			}
		}
		return ostr;
	}

	std::istream& TextFile::getFile(std::istream& istr) {
		char* name = new char[256];
		istr >> name;
		setFilename(name);
		delete[] name;
		setNoOfLines();
		loadText();
		return istr;
	}

	const char* TextFile::operator[](unsigned index)const {
		index = index % m_noOfLines;
		if (*this) {
			return m_textLines[index];
		}
		else {
			return nullptr;
		}
	}

	ostream& operator<<(ostream& ostr, const TextFile& text) {
		return text.view(ostr);
	}

	istream& operator>>(istream& istr, TextFile& text) {
		return text.getFile(istr);
	}
}