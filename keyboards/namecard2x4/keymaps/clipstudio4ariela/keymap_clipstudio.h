/* Copyright 2019 ariela
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * CLIP STUDIO PAINT Shortcuts
 *
 * For more information, see
 * https://www.clip-studio.com/site/gd/csp/manual/userguide/csp_userguide/900_shortcut/900_shortcut_0.htm
 * note: This website is written in Japanese.
 */
#ifndef KEYMAP_CLIPSTUDIOPAINT_H
#define KEYMAP_CLIPSTUDIOPAINT_H

#include "keymap.h"

// 共通のショートカット
#define CS_SUBTOOL_PREV             KC_COMM // 前のサブツールに切り替え
#define CS_SUBTOOL_NEXT             KC_DOT // 次のサブツールに切り替え
#define CS_MOVE_MODE                KC_SPACE // 手のひら
#define CS_ROTATE_MODE              LSFT(KC_SPACE) // 回転
#define CS_ZOOM_IN_MODE             LCTL(KC_SPACE) // 虫めがね(拡大)
#define CS_ZOOM_IN_MAC_MODE         LGUI(KC_SPACE) // 虫めがね(拡大)(MacOS)
#define CS_ZOOM_OUT_MODE            LALT(KC_SPACE) // 虫めがね(縮小)
#define CS_SWAP_MAIN_SUB_COLORS     KC_X // メインカラーとサブカラーを切り替え
#define CS_SWAP_DRAW_TRANS_COLORS   KC_C // 描画色と透明色を切り替え
#define CS_SELECT_LAYER_MODE        KC_LSHIFT||KC_LCTRL // レイヤー選択

// ツールのショートカット
#define CS_TOOL_ZOOM                KC_SLSH // 虫めがね
#define CS_TOOL_MOVE                KC_H // 移動（手のひら）
#define CS_TOOL_ROTATE              KC_R // 移動（回転）
#define CS_TOOL_OPERATION_OBJECT    KC_O // 操作（オブジェクト）
#define CS_TOOL_OPERATION_LAYER     KC_D // 操作（レイヤー選択）
#define CS_TOOL_OPERATION_TIMELINE  KC_L // 操作（ライトテーブル）/操作（タイムライン編集）
#define CS_TOOL_MOVE_LAYER          KC_K // レイヤー移動
#define CS_TOOL_SELECTION_RECTANGLE KC_M // 選択範囲
#define CS_TOOL_SELECTION_AUTO      KC_W // 自動選択
#define CS_TOOL_DROPPER             KC_I // スポイト
#define CS_TOOL_PEN                 KC_P // ペン/鉛筆
#define CS_TOOL_BRUSH               KC_B // 筆/エアブラシ/デコレーション
#define CS_TOOL_ERASER              KC_E // 消しゴム
#define CS_TOOL_MIX_COLOR           KC_J // 色混ぜ
#define CS_TOOL_FILL                KC_G // 塗りつぶし/グラデーション
#define CS_TOOL_FIGURE              KC_U // 図形/コマ枠/定規
#define CS_TOOL_TEXT                KC_T // テキスト/フキダシ
#define CS_TOOL_FIX_LINE            KC_Y // 線修正・ごみ取り

// ファイルメニュー
#define CS_FILE_NEW         LCTL(KC_N) // 新規
#define CS_FILE_NEW_MAC     LGUI(KC_N) // 新規(MacOS)
#define CS_FILE_OPEN        LCTL(KC_O) // 開く
#define CS_FILE_OPEN_MAC    LGUI(KC_O) // 開く(MacOS)
#define CS_FILE_CLOSE       LCTL(KC_W) // 閉じる
#define CS_FILE_CLOSE_MAC   LGUI(KC_W) // 閉じる(MacOS)
#define CS_FILE_SAVE        LCTL(KC_S) // 保存
#define CS_FILE_SAVE_MAC    LGUI(KC_S) // 保存(MacOS)
#define CS_FILE_SAVE_RENAME LSFT(LALT(KC_S)) // 別名で保存

// 編集メニュー
#define CS_EDIT_UNDO                    LCTL(KC_Z) // 取り消し
#define CS_EDIT_UNDO_MAC                LGUI(KC_Z) // 取り消し(MacOS)
#define CS_EDIT_REDO                    LCTL(KC_Y) // やり直し
#define CS_EDIT_REDO_MAC                LGUI(KC_Y) // やり直し(MacOS)
#define CS_EDIT_CUT                     KC_F2 // 切り取り
#define CS_EDIT_COPY                    KC_F3 // コピー
#define CS_EDIT_PASTE                   KC_F4 // 貼り付け
#define CS_EDIT_DELETE                  KC_BSPACE // 消去
#define CS_EDIT_DELETE_OUTER_SELECTION  LSFT(KC_BSPACE) // 選択範囲外を消去
#define CS_EDIT_FILL                    LALT(KC_BSPACE) // 塗りつぶし
#define CS_EDIT_HSV                     LCTL(KC_U) // 色相・彩度・明度
#define CS_EDIT_HSV_MAC                 LGUI(KC_U) // 色相・彩度・明度(MacOS)
#define CS_EDIT_TONE                    LCTL(KC_I) // 階調の反転
#define CS_EDIT_TONE_MAC                LGUI(KC_I) // 階調の反転(MacOS)
#define CS_EDIT_SCALE_ROTATE            LCTL(KC_T) // 拡大・縮小・回転
#define CS_EDIT_SCALE_ROTATE_MAC        LGUI(KC_T) // 拡大・縮小・回転(MacOS)
#define CS_EDIT_FREE_TRANSFORM          LCTL(LSFT(KC_T)) // 自由変形
#define CS_EDIT_FREE_TRANSFORM_MAC      LGUI(LSFT(KC_T)) // 自由変形(MacOS)

// レイヤーメニュー
#define CS_LAYER_NEW_LUSTER         LCTL(LSFT(KC_N)) // 新規ラスターレイヤー
#define CS_LAYER_NEW_LUSTER_MAC     LGUI(LSFT(KC_N)) // 新規ラスターレイヤー(MacOS)
#define CS_LAYER_CLIPPING           LCTL(LALT(KC_G)) // 下のレイヤーでクリッピング
#define CS_LAYER_CLIPPING_MAC       LGUI(LALT(KC_G)) // 下のレイヤーでクリッピング(MacOS)
#define CS_LAYER_UNION_UNDER        LCTL(KC_E) // 下のレイヤーと結合
#define CS_LAYER_UNION_UNDER_MAC    LGUI(KC_E) // 下のレイヤーと結合(MacOS)
#define CS_LAYER_UNION_SELECTION    LSFT(LALT(KC_E)) // 選択中のレイヤーを結合
#define CS_LAYER_UNION_DISPLAY      LCTL(LSFT(KC_E)) // 表示レイヤーを結合
#define CS_LAYER_UNION_DISPLAY_MAC  LGUI(LSFT(KC_E)) // 表示レイヤーを結合(MacOS)
#define CS_LAYER_EDITABLE_UPPER     LALT(KC_NUHS) // 編集対象にする(上のレイヤー)
#define CS_LAYER_EDITABLE_UNDER     LALT(KC_RBRC) // 編集対象にする(下のレイヤー)

// 選択範囲メニュー
#define CS_SELECTION_ALL            LCTL(KC_A) // すべてを選択
#define CS_SELECTION_ALL_MAC        LGUI(KC_A) // すべてを選択(MacOS)
#define CS_SELECTION_OFF            LCTL(KC_D) // 選択を解除
#define CS_SELECTION_OFF_MAC        LGUI(KC_D) // 選択を解除(MacOS)
#define CS_SELECTION_RESELECT       LCTL(LSFT(KC_D)) // 再選択
#define CS_SELECTION_RESELECT_MAC   LGUI(LSFT(KC_D)) // 再選択(MacOS)
#define CS_SELECTION_INVERT         LSFT(KC_F7) // 選択範囲を反転

// 表示メニュー
#define CS_CANVAS_ROTATE_LEFT               KC_MINS // 左回転
#define CS_CANVAS_ROTATE_RIGHT              KC_EQL // 右回転
#define CS_CANVAS_ZOOM_IN                   LCTL(KC_KP_PLUS) // ズームイン
#define CS_CANVAS_ZOOM_IN_MAC               LGUI(KC_KP_PLUS) // ズームイン(MacOS)
#define CS_CANVAS_ZOOM_OUT                  LCTL(KC_KP_MINUS) // ズームアウト
#define CS_CANVAS_ZOOM_OUT_MAC              LGUI(KC_KP_MINUS) // ズームアウト(MacOS)
#define CS_CANVAS_DISPLAY_100P              LCTL(LALT(KC_0)) // 100%表示
#define CS_CANVAS_DISPLAY_100P_MAC          LGUI(LALT(KC_0)) // 100%表示(MacOS)
#define CS_CANVAS_DISPLAY_OVERALL           LCTL(KC_0) // 全体表示
#define CS_CANVAS_DISPLAY_OVERALL_MAC       LGUI(KC_0) // 全体表示(MacOS)
#define CS_CANVAS_POSITION_RESET            LCTL(KC_LBRC) // 表示位置をリセット
#define CS_CANVAS_POSITION_RESET_MAC        LGUI(KC_LBRC) // 表示位置をリセット(MacOS)
#define CS_CANVAS_RULER                     LCTL(KC_R) // ルーラー
#define CS_CANVAS_RULER_MAC                 LGUI(KC_R) // ルーラー(MacOS)
#define CS_CANVAS_SNAP_RULER                LCTL(KC_1) // 定規にスナップ
#define CS_CANVAS_SNAP_RULER_MAC            LGUI(KC_1) // 定規にスナップ(MacOS)
#define CS_CANVAS_SNAP_SPECIAL_RULER        LCTL(KC_2) // 特殊定規にスナップ
#define CS_CANVAS_SNAP_SPECIAL_RULER_MAC    LGUI(KC_2) // 特殊定規にスナップ(MacOS)
#define CS_CANVAS_SNAP_GRID                 LCTL(KC_3) // グリッドにスナップ
#define CS_CANVAS_SNAP_GRID_MAC             LGUI(KC_3) // グリッドにスナップ(MacOS)
#define CS_CANVAS_SNAP_SR_CHANGE            LCTL(KC_4) // スナップする特殊定規の切り替え
#define CS_CANVAS_SNAP_SR_CHANGE_MAC        LGUI(KC_4) // スナップする特殊定規の切り替え(MacOS)

// ウィンドウメニュー
#define CS_WINDOW_CANVAS_NEXT               LCTL(KC_TAB) // 次のキャンバス
#define CS_WINDOW_CANVAS_NEXT_MAC           LGUI(KC_TAB) // 次のキャンバス(MacOS)
#define CS_WINDOW_CANVAS_PREV               LCTL(LSFT(KC_TAB)) // 前のキャンバス
#define CS_WINDOW_CANVAS_PREV_MAC           LGUI(LSFT(KC_TAB)) // 前のキャンバス(MacOS)
#define CS_WINDOW_TOGGLE_DIAPLAY_PALETTE    KC_TAB // すべてのパレットを表示する／隠す
#define CS_WINDOW_TOGGLE_DIAPLAY_TITLE_BAR  LSFT(KC_TAB) // タイトルバーを隠す／メニューバーを隠す

// ツールプロパティパレット
#define CS_OPACITY_DOWN             LCTL(KC_RBRC) // 不透明度を下げる
#define CS_OPACITY_DOWN_MAC         LGUI(KC_RBRC) // 不透明度を下げる(MacOS)
#define CS_OPACITY_UP               LCTL(KC_NUHS) // 不透明度を上げる
#define CS_OPACITY_UP_MAC           LGUI(KC_NUHS) // 不透明度を上げる(MacOS)
#define CS_TOGGLE_MULTI_REFERENCE   KC_0 // 複数参照のON/OFF

// ブラシサイズパレット
#define CS_BRUSH_SIZE_DOWN  KC_RBRC // 現在よりサイズの小さいプリセットを選択
#define CS_BRUSH_SIZE_UP    KC_NUHS // 現在よりサイズの大きいプリセットを選択

// レイヤープロパティパレット
#define CS_TOGGLE_USE_LAYER_COLOR       LCTL(KC_B) // レイヤーカラーの使用切り替え
#define CS_TOGGLE_USE_LAYER_COLOR_MAC   LGUI(KC_B) // レイヤーカラーの使用切り替え(MacOS)

#endif