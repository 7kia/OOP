#pragma once

#include <iostream>
#include <fstream>
#include <utility>
#include <vector>
#include <boost/algorithm/string.hpp>

/*
Класс, моделирующий рациональное число
*/
class CUrlParsingError : public std::invalid_argument
{
public:
private:
	const std::string MESSAGE_INCORRECT_PROTOCOL = "Incorrect protocol.";
};

class CHttpUrl
{
public:
	enum class Protocol
	{
			HTTP = 0
		,	HTTPS
	};
public:

	// выполняет парсинг строкового представления URL-а, в случае ошибки парсинга
	// выбрасыват исключение CUrlParsingError, содержащее текстовое описание ошибки
	CHttpUrl(std::string const& url);

	/* инициализирует URL на основе переданных параметров.
	При недопустимости входных параметров выбрасывает исключение
	std::invalid_argument
	Если имя документа не начинается с символа /, то добавляет / к имени документа
	*/
	CHttpUrl(std::string const& domain
			, std::string const& document
			, Protocol protocol = Protocol::HTTP
			, unsigned short port = 80);

	// возвращает строковое представление URL-а. Порт, являющийся стандартным для
	// выбранного протокола (80 для http и 443 для https) в URL не должен включаться
	std::string					GetURL() const;


	void						SetProtocol(const std::string & url);
	// возвращает доменное имя
	std::string					GetDomain() const;

	/*
	Возвращает имя документа. Примеры:
	/
	/index.html
	/images/photo.jpg
	*/
	std::string					GetDocument() const;

	// возвращает тип протокола
	Protocol					GetProtocol() const;

	// возвращает номер порта
	unsigned short				GetPort() const;
private:
	const std::string			HTTP_STRING_PRSENTATION = "HTTP";
	const std::string			HTTPS_STRING_PRSENTATION = "HTTPS";

	const size_t				AMOUNT_PARTS_URL = 3;
private:
	std::vector<std::string>	GetPartsUrl(std::string const& text);

	std::string RecogniteProtocol(const std::string & text
								, size_t & position);

	void						SetData(const std::string & protocol
										, std::string const& domain
										, std::string const& document
										, unsigned short port = 80);
private:
	std::string					m_domain;
	std::string					m_document;
	Protocol					m_protocol;
	unsigned short				m_port;
};
