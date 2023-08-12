/*
Full Name  : Ashwin Pandey
Student ID#: 156027211
Email      : apandey21@myseneca.ca
*/

#include "HtmlText.h"

using namespace std;
namespace sdds {
	HtmlText::HtmlText(const char* filename, const char* title) : Text(filename) {
		m_title = nullptr;
		//Text(filename);
		if (title != nullptr) {
			m_title = new char[strLen(title) + 1];
			strCpy(m_title, title);
		}
	}

	HtmlText::~HtmlText() {
		delete[] m_title;
	}

	HtmlText::HtmlText(const HtmlText& other) : Text(other) {
		//call the base constructor
		if (other.m_title != nullptr) {
			m_title = new char[strLen(other.m_title) + 1];
			strCpy(m_title, other.m_title);
		}
		
	}

	HtmlText& HtmlText::operator=(const HtmlText& other) {
		if (this == &other) // Self-assignment check
			return *this;

		delete[] m_title;

		Text::operator=(other);

		//Deep copy title
		if (other.m_title != nullptr) {
			m_title = new char[strLen(other.m_title) + 1];
			strCpy(m_title, other.m_title);
		}
		else {
			m_title = nullptr;
		}

		return *this;
	}

	void HtmlText::write(std::ostream& os)const {
		bool ms = false;

		os << "<html><head><title>";

		if (m_title != nullptr) {
			os << m_title;
		}
		else {
			os << "No title";
		}
		os << "</title></head>\n<body>\n";

		if (m_title != nullptr) {
			os << "<h1>" << m_title << "</h1>\n";
		}

		for (int i = 0; i < (int)*this; i++) {
			char ch = (*this)[i];
			switch (ch) {
			case ' ':
				if (ms) {
					os << "&nbsp;";
				}
				else {
					ms = true;
					os << ' ';
				}
				break;
			case '<':
				os << "&lt;";
				ms = false;
				break;
			case '>':
				os << "&gt;";
				ms = false;
				break;
			case '\n':
				os << "<br />\n";
				ms = false;
				break;
			default:
				os << ch;
				ms = false;
				break;
			}
		}
		os << "</body>\n</html>";
	}
}