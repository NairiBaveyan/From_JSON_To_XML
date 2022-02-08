
#ifndef _PARSER_
#define _PARSER_


using std::string;

class Parser{
public:
	Parser();
	Parser(string);

public:
	string Pars(string);
//	void setFileXML(string);
//	string getFileJSON();

private:
	
	string translate(string);
	string editName(string);
	string m_file_name_XML;
	string m_file_name_JSON;
	
};


#endif 
