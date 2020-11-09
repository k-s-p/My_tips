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
      このエラーがでる場合は以下のコマンドを使用する<br>
      `git remote set-url origin <URL>`

1. プッシュする
    1. `git add filename`
    1. `git commit -m "Comment"`
    1. `git push origin master`

1. プルする
    1. `git pull origin master`

- 状態を確認する
`git status`
- 変更履歴を確認する
`git log`, `git log -p`
- 変更の差分を見る
`git diff`

# ほかのコマンドについて
後日まとめよう～
