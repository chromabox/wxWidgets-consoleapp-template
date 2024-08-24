// The MIT License (MIT)
//
// Copyright (c) <2024> chromabox <chromarockjp@gmail.com>
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
#include "appmain.h"
#include <iostream>

#define LOCALE_SETJP_UTF8 1

wxDECLARE_APP(mainApp);
wxIMPLEMENT_APP_CONSOLE(mainApp);

// ---------------------------------------------------------------------------------

static const wxCmdLineEntryDesc cmdLineDesc[] =
{
	{ wxCMD_LINE_PARAM, NULL, NULL, _( "message" ).mb_str(),
		wxCMD_LINE_VAL_STRING, wxCMD_LINE_OPTION_MANDATORY },	
	{ wxCMD_LINE_SWITCH, "h", "help", "このメッセージを見る",
		wxCMD_LINE_VAL_NONE, wxCMD_LINE_OPTION_HELP },
	{ wxCMD_LINE_SWITCH, "d", "dummy", "a dummy switch" ,
		wxCMD_LINE_VAL_NONE, wxCMD_LINE_PARAM_OPTIONAL },

	{ wxCMD_LINE_NONE }
};

// コンソールアプリの初期化時に呼ばれる
bool mainApp::OnInit()
{
#ifdef LOCALE_SETJP_UTF8	
	// windows 10.0.17134.0 after or ubuntu
	 setlocale(LC_ALL, "ja_JP.UTF-8");		// これをしないとコンソールで日本語出力がうまくいかないです
#endif
	// コマンドライン引数を処理する
	if(!wxAppConsole::OnInit()){
		// 止める
		return false;
	}
	// ロガー作成
	auto *logger=new wxLogStream(&std::cout);
	wxLog::SetActiveTarget(logger);

	// trueを返すと動き続ける。false を返すと即座に終わります
	return true;
}

// コンソールアプリのコマンドライン解析前に呼ばれる
// コマンドライン定義をセットする
void mainApp::OnInitCmdLine(wxCmdLineParser &parser)
{
	parser.SetDesc(cmdLineDesc);
	parser.SetSwitchChars("-");
}

// コンソールアプリのコマンドライン解析時に呼ばれる
// 解析した結果でフラグのONOFFをしたりする
bool mainApp::OnCmdLineParsed(wxCmdLineParser &parser)
{
	if(parser.Found("d")){
		m_dummy_switch = true;
	}

	if(parser.GetParamCount() < 1){
		parser.Usage();
		return false;
	}
	m_message = parser.GetParam(0);

	return true;
}

// 実質的なコンソールアプリのMain
int mainApp::OnRun()
{
	wxPrintf(L"Welcome to the wxWidgets 'console' sample!\n");
	wxPrintf(L"Message is %s\n", m_message);
	wxPrintf(L"For more information, run it again with the --help option\n");
	if(m_dummy_switch){
		wxPrintf(L"-dが指定されました\n");
	}
	return 0;
}
