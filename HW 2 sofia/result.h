#pragma once

class result
{
public:
	result(const char*);
	result(const result&);
	result();
	~result();

	void print();
	void processBuffer(const char*);
	void copyFrom(const result &);

public:
	const char* getName()    const;
	const char* getSubject() const;
	const unsigned short getAge()	const;
	const unsigned short getDate()	const;
	const unsigned short getYear()	const;
	const unsigned short getGrade() const;
	const unsigned short getMonth() const;

public:
	bool isEmpty();
	bool operator!=(const result&);

	bool nameLess	(const result &); // A man has no name.
	bool nameGreater(const result &);
	bool ageLess	(const result &);
	bool ageGreater	(const result &);
	bool subjectLess	(const result &);
	bool subjectGreater	(const result &);
	bool gradeLess	 (const result &);
	bool gradeGreater(const result &);
	bool dateLess	(const result &); // me_irl
	bool dateGreater(const result &);

private:
	void setName	(const char*, unsigned short, unsigned short);
	void setSubject	(const char*, unsigned short, unsigned short);

	bool cmpCharsLess( char,  char);
	bool cmpCharsGreater( char,  char);
	bool cmpCharsEqual(char, char);

	bool cmpStringsLess(const char*, const char*);
	bool cmpStringsGreater(const char*, const char*);

	unsigned short charToNum(const char*, unsigned short, unsigned short);
	unsigned short nextChar (const char*, unsigned short, char);

private:
	char*		   name;
	unsigned short age;
	char		   subject[10];
	unsigned short grade;
	unsigned short date, month, year;
	bool isBad;
};