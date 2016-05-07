#pragma once

#include <boost/algorithm/string.hpp>

#include "UrlRecognizer.h"

class CHttpUrl
	: public CUrlRecognizer
{
public:
	enum  Protocol//class
	{
			HTTP = 80
		,	HTTPS = 443
	};
public:

	// выполняет парсинг строкового представления URL-а, в случае ошибки парсинга
	// выбрасыват исключение CUrlParsingError, содержащее текстовое описание ошибки
	CHttpUrl(const std::string & url);

	/* инициализирует URL на основе переданных параметров.
	При недопустимости входных параметров выбрасывает исключение
	std::invalid_argument
	Если имя документа не начинается с символа /, то добавляет / к имени документа
	*/
	CHttpUrl(Protocol protocol
			, std::string const& domain
			, std::string const& document
			, unsigned short port = 80);

	// возвращает строковое представление URL-а. Порт, являющийся стандартным для
	// выбранного протокола (80 для http и 443 для https) в URL не должен включаться
	std::string					GetURL() const;

	// возвращает доменное имя
	void						SetDomain(const std::string & domain);
	std::string					GetDomain() const;

	/*
	Возвращает имя документа. Примеры:
	/
	/index.html
	/images/photo.jpg
	*/
	void						SetDocument(const std::string & document);
	std::string					GetDocument() const;

	// возвращает тип протокола
	void						SetProtocol(const std::string & proctocol);
	void						SetProtocol(Protocol proctocol);
	Protocol					GetProtocol() const;
	std::string					GetStringPresentationProtocol() const;

	// возвращает номер порта
	void						SetPort(const std::string & port);
	void						SetPort(unsigned int port);
	unsigned short				GetPort() const;
private:
	const size_t				AMOUNT_PARTS_URL = 3;
private:
	void						SetData(const std::string & protocol
										, std::string const& domain
										, std::string const& document
										, unsigned short port = 80);
private:
	std::string					m_domain;
	std::string					m_document;

	Protocol					m_protocol = Protocol::HTTP;
	unsigned short				m_port = 80;
};
