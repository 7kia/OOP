#include "stdafx.h"
#include "DictionaryState.h"
#include "DictionaryEditor.h"

using namespace std;

bool needSetExitState(string input)
{
	if (input == STRING_FOR_EXIT)
	{
		return true;
	}
	return false;
}

CWaitTranslateWord::CWaitTranslateWord(CDictionaryEditor * pEditor)
{
	m_pEditor = pEditor;
	m_pEditor->m_numberState = CDictionaryEditor::numberState::Wait_translate_word;
}

void CWaitTranslateWord::ProcessString(string inputString)
{
	boost::algorithm::to_lower(inputString);

	if (!inputString.empty())
	{
		if (needSetExitState(inputString))
		{
			m_pEditor->SetState(new CBeforeExit(m_pEditor));
			PrintMessageBeforeExit();
			return;
		}

		auto foundElement = m_pEditor->m_dictionary.find(inputString);

		if (foundElement != m_pEditor->m_dictionary.end())
		{
			cout << foundElement->second << endl;
		}
		else
		{
			m_pEditor->m_unknowWord = inputString;
			m_pEditor->SetState(new CWaitTranslation(m_pEditor));
			PrintMessageAboutUnknowWord(m_pEditor->m_unknowWord);
		}
	}

}

CWaitTranslation::CWaitTranslation(CDictionaryEditor * pEditor)
{
	m_pEditor = pEditor;
	m_pEditor->m_numberState = CDictionaryEditor::numberState::Wait_translation;
}

void CWaitTranslation::ProcessString(string inputString)
{
	boost::algorithm::to_lower(inputString);

	if (!inputString.empty())
	{
		if (needSetExitState(inputString))
		{
			m_pEditor->SetState(new CBeforeExit(m_pEditor));
			PrintMessageBeforeExit();
			return;
		}

		m_pEditor->m_dictionary.insert({ m_pEditor->m_unknowWord, inputString });

		m_pEditor->SetState(new CWaitTranslateWord(m_pEditor));
		
		PrintMessageSuccessfullInsert(m_pEditor->m_unknowWord, inputString);

	}
	else
	{
		m_pEditor->SetState(new CWaitTranslateWord(m_pEditor));
		PrintMessageIgnoreWord(m_pEditor->m_unknowWord);
	}
}

CBeforeExit::CBeforeExit(CDictionaryEditor * pEditor)
{
	m_pEditor = pEditor;
	m_pEditor->m_numberState = CDictionaryEditor::numberState::Before_exit;
}

void CBeforeExit::ProcessString(string inputString)
{

	boost::algorithm::to_lower(inputString);

	if (!inputString.empty() && !m_pEditor->m_dictionary.empty())
	{
		if (inputString == STRING_FOR_SAVE)
		{
			m_pEditor->SetState(new CSaveDictionary(m_pEditor));
		}
		else
		{
			PrintMessageIncorectInput();
		}
	}
	else
	{
		m_pEditor->SetState(new CExit(m_pEditor));
	}
}

CSaveDictionary::CSaveDictionary(CDictionaryEditor *pEditor)
{
	m_pEditor = pEditor;
	PrintMessageDictionarySaveAs(m_pEditor->m_inputDictionaryIsEmpty, m_pEditor->m_fileName);

	m_pEditor->SaveDictionaryInFile();
	m_pEditor->SetState(new CExit(m_pEditor));
}

void CSaveDictionary::ProcessString(string inputString)
{
}

CExit::CExit(CDictionaryEditor * pEditor)
{
	pEditor->m_numberState = CDictionaryEditor::numberState::Exit;
}

void CExit::ProcessString(std::string inputString)
{
}

