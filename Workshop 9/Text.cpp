/*
Full Name  : Ashwin Pandey
Student ID#: 156027211
Email      : apandey21@myseneca.ca
*/

#include <fstream>
#include <iostream>
#include "Text.h"

using namespace std;
namespace sdds {
	int Text::getFileLength() const {
		int len = 0;
		ifstream fin(m_filename);
		while (fin) {
			fin.get();
			len += !!fin;
		}
		return len;
	}

	const char& Text::operator[](int index) const {
		return m_content[index];
	}

	void Text::setEmpty() {
		if (m_content != nullptr) {
			delete[] m_content;
		}
		if (m_filename != nullptr) {
			delete[] m_filename;
		}
		m_content = nullptr;
		m_filename = nullptr;
	}

	Text::Text(const char* filename) {
		m_filename = nullptr;
		m_content = nullptr;
		if (filename != nullptr) {
			m_filename = new char[strLen(filename) + 1];
			strCpy(m_filename, filename);
			read();
		}
	}

	Text::Text(const Text& other) {
		// Deep copy the filename
		if (other.m_filename != nullptr) {
			m_filename = new char[strLen(other.m_filename) + 1];
			strCpy(m_filename, other.m_filename);
		}

		// Deep copy the content
		if (other.m_content != nullptr) {
			m_content = new char[strLen(other.m_content) + 1];
			strCpy(m_content, other.m_content);
		}
	}

	Text& Text::operator=(const Text& other) {
		if (this == &other) // Self-assignment check
			return *this;

		// Release existing memory
		delete[] m_filename;
		delete[] m_content;

		// Deep copy the filename
		if (other.m_filename != nullptr) {
			m_filename = new char[strLen(other.m_filename) + 1];
			strCpy(m_filename, other.m_filename);
		}
		else {
			m_filename = nullptr;
		}

		// Deep copy the content
		if (other.m_content != nullptr) {
			m_content = new char[strLen(other.m_content) + 1];
			strCpy(m_content, other.m_content);
		}
		else {
			m_content = nullptr;
		}

		return *this;
	}
	
	Text::operator int()const {
		return getFileLength();
	}

	void Text::read() {
		ifstream file;
		if (m_filename != nullptr) {
			file.open(m_filename);
		}

		if (file) {
			if (m_content != nullptr) {
				delete[] m_content;
				m_content = nullptr;
			}
			int fileLength = getFileLength();
			m_content = new char[fileLength + 1];
			file.read(m_content, fileLength);
			m_content[fileLength] = '\0';
			file.close();
		}
		else {
			//cout << "Error reading file !" << endl;
			setEmpty();
		}
	}

	void Text::write(std::ostream& os)const {
		if (m_content != nullptr) {
			os << m_content;
		}
	}

	

	Text::~Text() {
		delete[] m_filename;
		delete[] m_content;
	}

	std::ostream& operator<<(std::ostream& os, const Text& text) {
		text.write(os);
		return os;
	}
}