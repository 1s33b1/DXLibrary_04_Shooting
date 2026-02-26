#include "DxLib.h"
#include "../GameParameter.h"
#include "Player.h"
#include "EnemyManager.h"
#include "Bullet.h"

/// <summary>
/// シューティング
/// 作成日：2026/2/20
/// メイン関数
/// 今はプレイヤーの当たり判定を行うのを実装途中
/// </summary>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// DXライブラリ初期化処理
	SetGraphMode(ScreenSettings::screenWidth, ScreenSettings::screenHeight, 30); // 画面のサイズを決定
	//SetWaitVSyncFlag(TRUE); // これを付けるとヌルヌルになりすぎて動作が何もかも早くなるからいったんなしで。
	if (DxLib_Init() == -1) return -1;
	SetDrawScreen(DX_SCREEN_BACK);
	SetMouseDispFlag(FALSE); // マウスカーソルを表示

	Player* pPlayer = new Player();
	EnemyManager* pEnemyManager = new EnemyManager();

	// メインのループ処理
	//----------------------------------------------------------------
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		ClearDrawScreen(); // 画面をまっさらに

		pPlayer->Update(pEnemyManager->GetEnemyBullets());
		pEnemyManager->Update(pPlayer->GetBullets()); // 敵全員分の更新処理
		pPlayer->Draw();
		pEnemyManager->Draw(); // 敵全員分の描画処理
		
		WaitTimer(50); // 待機時間
		ScreenFlip();    // 画面を更新して、少し休む	
	}


	///----------------------------------------------------------------
	/// 終了処理
	delete pEnemyManager;
	delete pPlayer;
	DxLib_End();				// ＤＸライブラリ使用の終了処理
	return 0;				// ソフトの終了 
}
