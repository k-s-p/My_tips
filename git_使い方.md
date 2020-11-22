![githubの使い方](https://cdn-ak.f.st-hatena.com/images/fotolife/i/itoken1013/20200529/20200529193757.png)

*バッククオート*<br>
*shift + @*
# githubの使い方
1. Gitにユーザー名とメールアドレスを登録する  
`$ git config --global user.name "ユーザー名"`<br>
`$ git config --global user.email "メールアドレス"`<br>

1. remote repositoryの作成
    1. githubのヘッダー右上にある「＋」をクリック
    1. 「New repository」をクリック
    1. [Repository name],その他設定をして、[Create repository]

1. local repositoryの準備
    1. cygwinでgitで管理するディレクトリへ移動<br>
    `cd directory_name`
    1. gitで管理するために以下のコマンド<br>
    ` $ git init`
    1. 先ほど作成したremote repositoryのURLをコピーする
    1. 以下のコマンドで、＜URL>の部分にコピーしたURLを使用<br>
    `$ git remote add origin <URL>`
      - 注意<br>
      <font color="Red">fatal: protocol 'https' is not supported</font><br>
      このエラーがでる場合は以下のコマンドを追記する使用する<br>
      `git remote set-url origin <URL>`

1. プッシュする
    1. `git add filename`
    1. `git commit -m "Comment"`
    1. `git push origin master`
    - 最近は、`git push origin main`に変更したほうが良いかも

1. プルする
    1. `git pull origin master`
    - 最初にプルしたほうが変な状態にならない
    - fetch+mergeをしている、個人で使用するだけならpullで十分？

- 状態を確認する
`git status`
- 変更履歴を確認する
`git log`, `git log -p`
- 変更の差分を見る
`git diff`

# ほかのコマンドについて
- git counfigでデフォルトのブランチを変更する<br>
  `git config --global init.defaultBranch main`

- 作成したmasterブランチをmainに変更する方法<br>
  `git branch -m master main`

- mergeエラー`refusing to merge unrelated histories`が発生する場合<br>
  `git merge --allow-unrelated-histories origin/main`
  - --allow-unrelated-historiesオプションについて<br>
    このオプションを付けないと無関係なヒストリを持つ2つのブランチをマージできない。リモートリポジトリ作成時に編集したREADMEをローカルに取り込まずにコミットしたから、ヒストリが別になったのかな、、、
