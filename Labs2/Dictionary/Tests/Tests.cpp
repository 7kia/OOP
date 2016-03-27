// Tests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../DictionaryEditor.h"

BOOST_AUTO_TEST_SUITE(DictionatyTestModule)


bool IsElementInDictionary(const dictionary & chechDictionary, const std::string &element)
{
	return chechDictionary.find(element) != chechDictionary.end();
}

BOOST_AUTO_TEST_CASE(Check_correctness_adding_and_unchanged_dictionary_without_saving)
{
	std::cout << "==========================================" << std::endl;

	setlocale(LC_ALL, "ru-RU");

	CDictionaryEditor editor("dict1.txt");
	dictionary startDictionary = editor.m_dictionary;

	editor.ProcessString("help");
	BOOST_CHECK(editor.GetIdState() == CDictionaryEditor::numberState::Wait_translation);

	editor.ProcessString("помощь");
	BOOST_CHECK(editor.GetIdState() == CDictionaryEditor::numberState::Wait_translate_word);
	BOOST_CHECK(IsElementInDictionary(editor.m_dictionary, "help"));

	editor.ProcessString("sdfax");
	BOOST_CHECK(editor.GetIdState() == CDictionaryEditor::numberState::Wait_translation);

	editor.ProcessString("");
	BOOST_CHECK(editor.GetIdState() == CDictionaryEditor::numberState::Wait_translate_word);

	editor.ProcessString(".");
	BOOST_CHECK(editor.GetIdState() == CDictionaryEditor::numberState::Before_exit);

	editor.ProcessString("");
	BOOST_CHECK(editor.GetIdState() == CDictionaryEditor::numberState::Exit);

	BOOST_CHECK(CreateDictionary("dict1.txt") == startDictionary);
}

BOOST_AUTO_TEST_CASE(Check_searching_different_register_words_and_changed_dictionary_after_saving)
{
	std::cout << "==========================================" << std::endl;
	CDictionaryEditor editor("dict2.txt");

	editor.ProcessString("help");
	BOOST_CHECK(editor.GetIdState() == CDictionaryEditor::numberState::Wait_translation);

	editor.ProcessString("помощь");
	BOOST_CHECK(editor.GetIdState() == CDictionaryEditor::numberState::Wait_translate_word);
	BOOST_CHECK(IsElementInDictionary(editor.m_dictionary, "help"));

	editor.ProcessString("HeLp");
	BOOST_CHECK(editor.GetIdState() == CDictionaryEditor::numberState::Wait_translate_word);

	editor.ProcessString("seed");
	BOOST_CHECK(editor.GetIdState() == CDictionaryEditor::numberState::Wait_translate_word);

	editor.ProcessString("SeEd");
	BOOST_CHECK(editor.GetIdState() == CDictionaryEditor::numberState::Wait_translate_word);

	editor.ProcessString(".");
	BOOST_CHECK(editor.GetIdState() == CDictionaryEditor::numberState::Before_exit);

	editor.ProcessString("");
	BOOST_CHECK(editor.GetIdState() == CDictionaryEditor::numberState::Exit);

	BOOST_CHECK(CreateDictionary("dict2out.txt") == editor.m_dictionary);
}


BOOST_AUTO_TEST_CASE(Check_on_empty_dictionary_file)
{
	std::cout << "==========================================" << std::endl;

	setlocale(LC_ALL, "ru-RU");

	CDictionaryEditor editor("dict3.txt");
	BOOST_CHECK(editor.m_dictionary.empty());

	editor.ProcessString("help");
	BOOST_CHECK(editor.GetIdState() == CDictionaryEditor::numberState::Wait_translation);

	editor.ProcessString("помощь");
	BOOST_CHECK(editor.GetIdState() == CDictionaryEditor::numberState::Wait_translate_word);
	BOOST_CHECK(IsElementInDictionary(editor.m_dictionary, "help"));

	editor.ProcessString(".");
	BOOST_CHECK(editor.GetIdState() == CDictionaryEditor::numberState::Before_exit);

	editor.ProcessString("s");
	BOOST_CHECK(editor.GetIdState() == CDictionaryEditor::numberState::Exit);



	BOOST_CHECK(CreateDictionary("dict3out.txt") == editor.m_dictionary);
}


BOOST_AUTO_TEST_SUITE_END()


