# wxWidgets-consoleapp-template
これは`wxWidgets`(C++用クロスプラットフォームGUIライブラリ)を使用してGUI抜きの「コンソールアプリケーション」を作るときの基本的なテンプレートサンプルです  
もともとGUIライブラリである`wxWidgets`でコンソールアプリケーションを作るという機会はあまりないかもしれませんが、`wxWidgets`はwxStringやwxFileName,wxSocketServerなどGUI抜きでも便利クラスが結構あるため、GUIなしでも純粋にC++のクラスとして使いたい…ということもあるかなと思い作りました  
現在(2024年)でもメンテされていてクロスプラットホームというのも大きいですね  
  
なお、通常の`wxWidgets`とのビルド設定、Mainの書き方など少し異なるため作成しました  
  
`cmake`で`wxWidgets`のコンソールアプリケーションをビルドする時のサンプルにもなっています   
github画面の右端にある`use this template`ボタンを押すだけでwxWidgetsのプロジェクトの雛形から起こすことが出来ます  
  
ubuntu 22.04の環境で動作確認済  
  
  
wxWidgetsについてはこちら  
https://www.wxwidgets.org/  
https://github.com/wxWidgets/wxWidgets  
  
## ビルド方法(ubuntu/linux):

cmake とか wxWidgetsの開発用ライブラリ(〜dev)は必要なのでインストールします。
```
$ sudo apt install build-essential cmake
$ sudo apt install libwxbase3.0-dev libwxsmithlib-dev libwxsvg-dev
```

次に、github画面の右端にある`use this template`ボタンを押してプロジェクトを作ります。  
その後cloneしてから  
```bash
$ ./build.sh
```
でとりあえずビルド出来ます。  
  

## TODO:
- Windowsでの例を入れる