#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include "XML_Parser_to_JSON.h"



Parser::Parser()
{}


Parser::Parser(string file_name)
	:m_file_name_XML{file_name}
{
	m_file_name_JSON = Pars(m_file_name_XML);
}

string Parser::editName(string word)
{
	string tmp = word.substr(0,word.size()-4);
	word+="json";
	return tmp;
}


string Parser::Pars(string file_name)
{
	std::vector<string> word_vec;
	std::ifstream fin;
	fin.open(file_name);
	if(fin.is_open())
	{
		string word;
		while(!fin.eof())
		{
			fin>>word;
			word_vec.push_back(translate(word));
		}
	}
	else{
		return "ifstream problem";
	}
	std::ofstream fout;
	m_file_name_JSON = editName(file_name);
	fout.open(m_file_name_JSON);
	if(fout.is_open())
	{
		for(auto& elem:word_vec)
		{
			fout<<elem;

		}
	}else{
		return "ofstream problem";
	}
	return m_file_name_JSON;
}

string Parser::translate(string word)
{
	string tmp;
	if(word[0]=='<'&& word[1]!='/')
	{
                tmp+='{';
		tmp.push_back('\n');
                tmp.push_back(34);
		for(int i{1};i < word.size()-1;++i)
		{
			tmp+=word[i];
		}
		tmp.push_back(34);
		tmp.push_back(':');
	}else if(word[0]=='<'&& word[1]=='/')
	{
		tmp.push_back('\n');
		tmp += "   }";
		//std::cout<<" tmp ="<<tmp;
	}else if(word[0]!='<')
	{
		tmp.push_back(34);
		tmp += word;
		tmp+=34;
	}

	return tmp;
}


