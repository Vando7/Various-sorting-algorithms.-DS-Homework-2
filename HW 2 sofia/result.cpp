#include "result.h"
#include<iostream>


result::result(const char *buffer)
	: 
	name(nullptr), 
	subject(""), 
	age	 (0), 
	grade(0), 
	date (0), 
	month(0), 
	year (0),
	isBad(1)
{
	processBuffer(buffer);
}

result::result(const result &dory) :
	name(nullptr),
	subject(""),
	age(0),
	grade(0),
	date(0),
	month(0),
	year(0),
	isBad(1)
{
	copyFrom(dory);
}


result::result()
	:
	name(nullptr),
	subject(""),
	age	 (0),
	grade(0),
	date (0),
	month(0),
	year (0),
	isBad(1)
{}


result::~result(){
	delete[] name;
}


void result::print(){
	if (!isBad)
		std::cout <<
			name	<< " " <<
			age		<< " " <<
			subject << " " <<
			grade	<< " " <<
			year	<< " " <<
			month	<< " " <<
			date	<<"\n";
}

// Read the data buffer and assign proper values.
// (We kind of assume that the buffer is proper)
void result::processBuffer(const char *buffer){
	if (!strlen(buffer)) {
		isBad = true;
		return;
	}

	isBad = false;

	unsigned short
		stPt = 0,
		edPt = 0,
		idx = 0;

	char delimiter = ',';

	for (int i = 0; i < 7; ++i) {
		if (i == 4)	delimiter = '-';
		else
			if (i == 6) delimiter = '\n';

		edPt = nextChar(buffer, idx, delimiter);

		switch (i) {
		case 0: setName(buffer, stPt, edPt);					break;
		case 2:	setSubject(buffer, stPt, edPt);					break;
		case 1:	age   = charToNum(buffer, stPt - 1, edPt - 1);	break;
		case 3: grade = charToNum(buffer, stPt - 1, edPt - 1);	break;
		case 4:	year  = charToNum(buffer, stPt - 1, edPt - 1);	break;
		case 5:	month = charToNum(buffer, stPt - 1, edPt - 1);	break;
		case 6: date  = charToNum(buffer, stPt - 1, edPt - 1);	break;
		}

		idx = stPt = edPt + 1;
	}
}


void result::copyFrom(const result &_result){
	if (!_result.getName()){
		isBad = true;
		return;
	}

	isBad = false;
	setName(_result.getName(), 0, strlen(_result.getName()));
	strcpy(subject, _result.getSubject());

	age   = _result.getAge();
	grade = _result.getGrade();
	date  = _result.getDate();
	month = _result.getMonth();
	year  = _result.getYear();
}

//-----| "Get" functions START
const char * result::getName() const{
	return name;
}


const char * result::getSubject() const{
	return subject;
}


const unsigned short result::getAge() const{
	return age;
}


const unsigned short result::getGrade() const{
	return grade;
}


const unsigned short result::getDate() const{
	return date;
}


const unsigned short result::getMonth() const{
	return month;
}


const unsigned short result::getYear() const {
	return year;
}


//-----| "Get" functions END

// "isBad" should be true generally whenever the name
// string is empty.
bool result::isEmpty(){
	return isBad;
}

bool result::operator!=(const result &a)
{
	if (strcmp(name, a.getName()) != 0)
		return true;
	if (strcmp(subject, a.getSubject()) != 0)
		return true;
	if (age != a.getAge())
		return true;
	if (year != a.getYear() || date != a.getDate() || month != a.getMonth())
		return true;

	return false;
}

//-----| Comparison functions START
bool result::nameLess(const result & _result){
	return cmpStringsLess(name, _result.getName());
}


bool result::nameGreater(const result & _result){
	return cmpStringsGreater(name, _result.getName());
}


bool result::ageLess(const result & _result){
	return age < _result.getAge();
}


bool result::ageGreater(const result & _result) {
	return age > _result.getAge();
}


bool result::subjectLess(const result & _result){
	return cmpStringsLess(subject, _result.getSubject());
}


bool result::subjectGreater(const result & _result){
	return cmpStringsGreater(subject, _result.getSubject());
}

bool result::gradeLess(const result &_result){
	return grade < _result.getGrade();
}


bool result::gradeGreater(const result &_result) {
	return grade > _result.getGrade();
}


bool result::dateLess(const result &_result){
	if (year < _result.getYear())
		return true;
	if (year > _result.getYear())
		return false;

	if (month < _result.getMonth())
		return true;
	if (month > _result.getMonth())
		return false;

	if (date < _result.getDate())
		return true;

	return false;
}


bool result::dateGreater(const result &_result){
	if (year > _result.getYear())
		return true;
	if (year < _result.getYear())
		return false;

	if (month > _result.getMonth())
		return true;
	if (month < _result.getMonth())
		return false;

	if (date > _result.getDate())
		return true;

	return false;
}
//-----| Comparison functions END

// Takes an input string and a pair of points: start and end.
void result::setName(	const char *buffer, 
						unsigned short stPt, 
						unsigned short edPt	)
{
	unsigned short	size = edPt - stPt + 1, 
					idx = 0;
	
	delete[] name;

	name = new char[size];

	while (stPt != edPt) {
		name[idx]= buffer[stPt];
		++stPt;
		++idx ;
	}
	
	name[size-1] = '\0';
}

// Takes an input string and a pair of points: start and end.
void result::setSubject(	const char *buffer,
							unsigned short stPt,
							unsigned short edPt	)
{
	unsigned short idx = 0;
	while (stPt != edPt) {
		subject[idx] = buffer[stPt];
		++stPt;
		++idx ;
	}
}


bool result::cmpCharsLess(char a,char b)
{
	a = a >= 'a' && a <= 'z' ? a - 'a' + 'A': a;
	b = b >= 'a' && b <= 'z' ? b - 'a' + 'A': b;
	return a < b;
}

bool result::cmpCharsGreater(char a, char b)
{
	a = a >= 'a' && a <= 'z' ? a - 'a' + 'A' : a;
	b = b >= 'a' && b <= 'z' ? b - 'a' + 'A' : b;
	return a > b;
}

bool result::cmpCharsEqual(char a, char b)
{
	a = a >= 'a' && a <= 'z' ? a - 'a' + 'A' : a;
	b = b >= 'a' && b <= 'z' ? b - 'a' + 'A' : b;
	return a == b;
}

bool result::cmpStringsLess(const char* a, const char* b)
{
	int minSize =strlen(a) < strlen(b) ? strlen(a) : strlen(b);
	bool flag = 0;
	
	for (short int i = 0; i < minSize; ++i) {	
		if (cmpCharsLess(a[i], b[i]))
			return 1;
		if (cmpCharsGreater(a[i], b[i]))
			return 0;
	}

	return 1;
}

bool result::cmpStringsGreater(const char *a, const char *b)
{
	int minSize = strlen(a) < strlen(b) ? strlen(a) : strlen(b);

	for (short int i = 0; i < minSize ; ++i) {
		if (cmpCharsGreater(a[i], b[i]))
			return 1;
		if (cmpCharsLess(a[i], b[i]))
			return 0;
	}

	return 1;
}

// Convert string to number. 
unsigned short result::charToNum(	const char *buffer, 
									unsigned short stPt, 
									unsigned short edPt  )
{
	unsigned short sum = 0, power = 1;
	while (edPt != stPt) {
		sum += (buffer[edPt] - '0') * power;
		power *= 10;
		--edPt;
	}

	return sum;
}

// Returns the the index of the first occurence 
// of the delimiter, starting from the given index.
unsigned short result::nextChar(	const char		*buffer, 
									unsigned short	idx,
									char			delimiter)
{
	while (buffer[idx] != delimiter && buffer[idx] != '\0')
		++idx;

	return idx;
}
