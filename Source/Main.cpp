#include "DxLib.h"
#include "../GameParameter.h"
#include "Player.h"
#include "Enemy.h"

/// <summary>
/// シューティング
/// 作成日：2026/2/20
/// メイン関数
/// </summary>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// DXライブラリ初期化処理
	SetGraphMode(ScreenSettings::screenWidth, ScreenSettings::screenHeight, 30); // 画面のサイズを決定
	//SetWaitVSyncFlag(TRUE); // これを付けるとヌルヌルになりすぎて動作が何もかも早くなるからいったんなしで。
	if (DxLib_Init() == -1) return -1;
	SetDrawScreen(DX_SCREEN_BACK);
	SetMouseDispFlag(FALSE); // マウスカーソルを表示

	Player* pPlayer;
	Enemy* pEnemy;
	pPlayer = new Player();
	pEnemy = new Enemy();


	// メインのループ処理
	//----------------------------------------------------------------
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		ClearDrawScreen(); // 画面をまっさらに

		pPlayer->Draw();
		pPlayer->Update();
		pEnemy->Draw();
		pEnemy->Update();

		WaitTimer(50); // 待機時間
		ScreenFlip();    // 画面を更新して、少し休む	
	}

	///------------------------------------------------------
	/// 終了処理
	delete pPlayer;
	DxLib_End();				// ＤＸライブラリ使用の終了処理
	return 0;				// ソフトの終了 
}
