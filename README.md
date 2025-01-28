# eHMI-sound

## 概要
本リポジトリでは、音声によるロボットと歩行者間の先行・後行情報を周辺歩行者に伝えるROSノード `/eHMI/sound_maker` を提供します。

---

## システム情報
- **プロジェクト名**: eHMI-sound
- **最終編集日**: 2025年1月28日
- **開発環境**:
  - **ハードウェア**: MSI GF63 Thin MS-16R4
  - **OS**: Ubuntu 20.04
  - **プラットフォーム**: ROS
  - **使用言語**: C++

---

## 機能
### 主なトピック
- **購読トピック**: `/eHMI/judgment`
  - パブリッシュ元: `/eHMI/judgment_maker`

### ノードの処理概要
1. `/eHMI/judgment` トピックを購読します。
2. 購読したデータには、ロボットと歩行者のどちらが衝突点を先行するかの判断が格納されています。
3. この判断結果を基に、音声によって周辺歩行者に先行者情報を伝えます。
   - 例: ビープ音や日本語音声でのアナウンス。

### 応用例
- 音声内容を調整することで、特定の環境やユーザーニーズに適応可能。
  - 例: ビープ音、特定の言語（日本語や英語）によるアナウンス。

---

## 注意事項
- **守秘義務**: 以下の内容は非公開です。
  - ノードグラフ全体の構造。
  - プログラム全体を動かすためのlaunchファイル。
- 現在、`/eHMI/judgment_maker` の判断生成にチャタリングが発生する問題があり、このノードの出力にも影響を与える場合があります。

---

## 映像
以下は実際の映像です。参考までにご覧ください。
[動画はこちらから視聴できます](https://youtube.com/shorts/LdvUZUPPug0)
<video src="./eHMI_sound_ver1-2024-07-22.mp4" controls width="640"></video>

