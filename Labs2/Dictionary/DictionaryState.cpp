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

void StateWaitTranslateWord::ProcessString(CDictionaryEditor &pEditor, string inputString)
{
	boost::algorithm::to_lower(inputString);

	if (!inputString.empty())
	{
		if (needSetExitState(inputString))
		{
			pEditor.SetIdState(CDictionaryEditor::numberState::Before_exit);
			PrintMessageBeforeExit();
			return;
		}

		auto foundElement = pEditor.m_dictionary.find(inputString);

		if (foundElement != pEditor.m_dictionary.end())
		{
			cout << foundElement->second << endl;
		}
		else
		{
			pEditor.m_unknowWord = inputString;
			pEditor.SetIdState(CDictionaryEditor::numberState::Wait_translation);
			PrintMessageAboutUnknowWord(pEditor.m_unknowWord);
		}
	}

}

void StateWaitTranslation::ProcessString(CDictionaryEditor &pEditor, string inputString)
{
	boost::algorithm::to_lower(inputString);

	if (!inputString.empty())
	{
		if (needSetExitState(inputString))
		{
			pEditor.SetIdState(CDictionaryEditor::numberState::Before_exit);
			PrintMessageBeforeExit();
			return;
		}

		pEditor.m_dictionary.insert({ pEditor.m_unknowWord, inputString });

		pEditor.SetIdState(CDictionaryEditor::numberState::Wait_translate_word);
		
		PrintMessageSuccessfullInsert(pEditor.m_unknowWord, inputString);

	}
	else
	{
		pEditor.SetIdState(CDictionaryEditor::numberState::Wait_translate_word);
		PrintMessageIgnoreWord(pEditor.m_unknowWord);
	}
}

void StateBeforeExit::ProcessString(CDictionaryEditor &pEditor, string inputString)
{

	boost::algorithm::to_lower(inputString);

	if (!inputString.empty() && !pEditor.m_dictionary.empty())
	{
		if (inputString == STRING_FOR_SAVE)
		{
			pEditor.SetIdState(CDictionaryEditor::numberState::Save_dictionary);
		}
		else
		{
			PrintMessageIncorectInput();
		}
	}
	else
	{
		pEditor.SetIdState(CDictionaryEditor::numberState::Exit);
	}
}

/*

CWaitTranslateWord::CWaitTranslateWord(CDictionaryEditor * pEditor)
{
pEditor = pEditor;
pEditor->m_numberState = CDictionaryEditor::numberState::Wait_translate_word;
}

CBeforeExit::CBeforeExit(CDictionaryEditor * pEditor)
{
	pEditor = pEditor;
	pEditor->m_numberState = CDictionaryEditor::numberState::Before_exit;
}

CSaveDictionary::CSaveDictionary(CDictionaryEditor &pEditor)
{
	pEditor = pEditor;
	PrintMessageDictionarySaveAs(pEditor->m_inputDictionaryIsEmpty, pEditor->m_fileName);

	pEditor->SaveDictionaryInFile();
	pEditor->SetState(new CExit(pEditor));
}




CExit::CExit(CDictionaryEditor * pEditor)
{
	pEditor->m_numberState = CDictionaryEditor::numberState::Exit;
}

void CExit::ProcessString(std::string inputString)
{
}

*/

