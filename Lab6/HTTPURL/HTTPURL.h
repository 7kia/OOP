#pragma once


#include <boost/algorithm/string.hpp>
#include <boost/regex.hpp>

#include "UrlParsingError.h"

class CHttpUrl
{
public:
	enum class Protocol
	{
			HTTP = 80
		,	HTTPS = 443
	};
public:

	// выполняет парсинг строкового представления URL-а, в случае ошибки парсинга
	// выбрасыват исключение CUrlParsingError, содержащее текстовое описание ошибки
	CHttpUrl(const std::string & url);



	void RecordProtocol(const boost::cmatch & recogniteUrl);
	void RecordDomain(const boost::cmatch & recogniteUrl);
	void RecordPort(const boost::cmatch & recogniteUrl);
	void RecordDocument(const boost::cmatch & recogniteUrl);

	void JoinSlashToDomain();


	/* инициализирует URL на основе переданных параметров.
	При недопустимости входных параметров выбрасывает исключение
	std::invalid_argument
	Если имя документа не начинается с символа /, то добавляет / к имени документа
	*/
	CHttpUrl(std::string const& domain
			, std::string const& document
			, Protocol protocol = Protocol::HTTP
			, unsigned short port = 0);

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
	const std::string			HTTP_STRING_PRSENTATION = "http";
	const std::string			HTTPS_STRING_PRSENTATION = "https";

	const std::string			PROTOCOL_RULE = "(http|https|ftp)";
	const std::string			PROTOCOL_DIVIDER = "://";

	const std::string			DOMAIN_RULE = "([^/:]+)";
	const std::string			PORT_RULE = ":?([^/ ]*)";

	const std::string			DOCUMENT_RULE = "/([^ ]*)";



	const size_t				AMOUNT_PARTS_URL = 3;
private:
	void						RecogniteDivederProtocol(const std::string & text, size_t & position);

	void						SetData(const std::string & protocol
										, std::string const& domain
										, std::string const& document
										, unsigned short port = 0);
private:
	std::string					m_domain;
	std::string					m_document;
	//string						m_host;// TODO : might excess
	Protocol					m_protocol = Protocol::HTTP;
	unsigned short				m_port = 0;
};
