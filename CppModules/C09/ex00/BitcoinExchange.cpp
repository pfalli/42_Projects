#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
    return ;
}

BitcoinExchange::BitcoinExchange(std::string fileName) {
    std::fstream file;
    file.open("data.csv", std::ios::in);
    if (!file.is_open() && !file.good())
        throw std::runtime_error("Cannot open file .csv");
    parsing_csv(file);
    file.close();
    std::fstream file2;
    file2.open(fileName.c_str(), std::ios::in);
    if (!file2.is_open() && !file2.good())
        throw std::runtime_error("Cannot open input file .txt");
    calculate(file2);
}


BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
    (void) other;
    return ;
}


BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
    if (this != &other) {
        
    }
    return *this;
}


BitcoinExchange::~BitcoinExchange() {
    return ;
}

//-----------------------------------------------------
//               FUNCTIONS
//----------------------------------------------------



void BitcoinExchange::parsing_csv(std::fstream &file) {
    std::string line;
    bool test = false;
    while (std::getline(file, line)) {
        if (!test) {
            if (strcmp(line.c_str(), "date,exchange_rate"))
                throw std::runtime_error("First line in file csv is wrong: " + line);
            test = true;
            continue;
        }
        std::stringstream ss(line); // stringstream is used to parse a string into individual components
        std::string date;
        std::string exchange_rate_str;
        if (std::getline(ss, date, ',') && std::getline(ss, exchange_rate_str, ',' )) {
            trim(date); // MISTAKE: i was trimming before getting the line
            trim(exchange_rate_str);
            char* end = NULL;
            double exchange_rate = strtod(exchange_rate_str.c_str(), &end);
            if (*end != '\0') {
                throw std::runtime_error("Invalid exchange rate: " + exchange_rate_str);
            }
            checker_csv(date, exchange_rate);
            this->container[date] = exchange_rate;
        }
    }

}

bool check_date_format(std::string date) { // std::istringstream + std::getline '-' +  std::istringstream(year_str) >> year;
    std::string year, month, day;
    if (date[4] != '-' || date[7] != '-')
        return false;
    if (date.size() != 10)
        return false;
    year = date.substr(0, 4);
    month = date.substr(5, 2);
    day = date.substr(8, 2);
    if (year < "2009" || year > "2022") {
        // std::cout << "here1" << year << std::endl; // Debug
        return false;
    }
    if (month < "01" || month > "12") {
        // std::cout << "here2 " << month << std::endl; // Debug
        return false;
    }
    if (day < "01" || day > "31") {
        // std::cout << "here3 " << day << std::endl; // Debug
        return false;
    }
    return true;
}

bool check_digits(std::string date) {
    for (size_t i = 0; i < date.size(); ++i) {
        if (date[i] != '-' && !std::isdigit(date[i])) {
            return false;
        }
    }
    return true;
}



void BitcoinExchange::checker_csv(std::string date, double exchange_rate) {
    if (exchange_rate < 0) {
        throw std::runtime_error("Error csv: not a positive number.");
    }
    if (exchange_rate > INT_MAX) {
        throw std::runtime_error("Error csv: too large a number");
    }
    if (!check_digits(date)) {
        std::ostringstream oss;
        oss << "Error csv: date has non-digits chars => " << date;
        throw std::runtime_error(oss.str());
    }
    if (!check_date_format(date)) {
        std::ostringstream oss;
        oss << "Error csv: bad input => " << date;
        throw std::runtime_error(oss.str());
    }
    if (container.find(date) != container.end()) {
        throw std::runtime_error("Error csv: date already exist");
    }

}

int BitcoinExchange::checker_txt(std::string date, double exchange_rate) {
    if (exchange_rate < 0) {
        std::cout << "Error: not a positive number." << std::endl;
        return 1;
    }
    if (exchange_rate > INT_MAX) {
        std::cout << "Error: too large a number" << std::endl;
        return 1;
    }
    if (!check_digits(date)) {
        std::cout << "Error: bad input => " << std::endl;
        return 1;
    }
    if (!check_date_format(date)) {
        std::cout << "Error: bad format => " << date << std::endl;
        return 1;
    }
    // if (container.find(date) != container.end()) {
    //     std::cout << "Error: date already exist" << std::endl;
    //     return 1;
    // }
    return 0;
}

void BitcoinExchange::print_container() {
    std::cout << "test printing container" << std::endl;
    for (std::map<std::string, double>::iterator it = this->container.begin(); it != this->container.end(); it++) {
        std::cout << "data: " << it->first << " - value: " << it->second << std::endl;
    }
}

void trim(std::string &val)
{
	if (!val.size())
		return ;
	size_t	pos = 0;
	while (pos < val.size() && std::isspace(val[pos]))
		pos++;
	if (pos > 0)
		val.erase(0, pos);
	pos = 0;
	while (val.size() > 0 && std::isspace(val[val.size() - 1]))
		val.erase(val.size() - 1, 1);
}

void BitcoinExchange::calculate(std::fstream &file) {
    std::string line;
    bool test = false;
    while (std::getline(file, line)) {
        if (!test) {
            if (!strcmp(line.c_str(), "date | value"))
                throw std::runtime_error("First line in input.txt is wrong: " + line);
            test = true;
            continue;
        }
        std::stringstream ss(line);
        std::string date_str;
        std::string value_str;
        if (std::getline(ss, date_str, '|') && std::getline(ss, value_str, '|')){
            trim(date_str);
            trim(value_str);
            char* end = NULL;
            double value = strtod(value_str.c_str(), &end);
            // if (*end != '\0') {
            //     throw std::runtime_error("Invalid value: " + value_str);
            // }
            moltiplication(date_str, value);
        }
        else {
            std::cout << "Error: bad input => " << line << std::endl;
        }
    }

}


void BitcoinExchange::moltiplication(std::string date_txt, double value_txt) {
    if  (checker_txt(date_txt, value_txt) == 1) // check for errors in txt
        return ;
    std::map<std::string, double>::iterator it = container.find(date_txt);
    
    if (it != container.end()) { // Date found and return
        std::cout << date_txt << " => " << value_txt << " = " << value_txt * it->second << std::endl;
        return;
    }
    it = container.lower_bound(date_txt);
    if (it == container.begin() && it->first > date_txt) {
        std::cout << "No data available for " << date_txt << std::endl;
        return;
    }
    if (it != container.end() && it->first == date_txt) { // Date changed, found and return
        std::cout << date_txt << " => " << value_txt << " = " << value_txt * it->second << std::endl;
        return;
    }
    if (it != container.begin()) { // Not found and decrease
        --it;
    }
    std::cout << date_txt << " => " << value_txt << " = " << value_txt * it->second << std::endl;
}
