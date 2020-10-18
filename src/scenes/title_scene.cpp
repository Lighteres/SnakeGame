#include "scenes/title_scene.h"

void TitleScene::OnCreate() {}
void TitleScene::OnRender() {
  terminal_clear();
  terminal_print(25, 5, "Snake Game");
  terminal_print(20, 15, "Press Enter to start");
  terminal_print(18, 17, "Current difficulty: ");
  terminal_print(13, 24, "Press '1' to select easy difficulty");
  terminal_print(13, 26, "Press '2' to select medium difficulty");
  terminal_print(13, 28, "Press '3' to select hard difficulty");
  if (gs_->IsEasy) {
    terminal_print(38, 17, "Easy");
  }
  if (gs_->IsMedium) {
    terminal_print(38, 17, "Medium");
  }
  if (gs_->IsHard) {
    terminal_print(38, 17, "Hard");
  }
  if (controls_.IsPressed(TK_1)) {
    gs_->IsHard = false;
    gs_->IsMedium = false;
    gs_->IsEasy = true;
    gs_->speed = 0.1;
  }
  if (controls_.IsPressed(TK_2)) {
    gs_->IsHard = false;
    gs_->IsEasy = false;
    gs_->IsMedium = true;
    gs_->speed = 0.2;
  }
  if (controls_.IsPressed(TK_3)) {
    gs_->IsMedium = false;
    gs_->IsEasy = false;
    gs_->IsHard = true;
    gs_->speed = 0.3;
  }
  if (controls_.IsPressed(TK_ENTER)) {
    ctx_->scene_ = "game";
  }
  terminal_refresh();
}
void TitleScene::OnExit() {
  engine.GetSystemManager()->DeleteAll();
}
TitleScene::TitleScene(Context* ctx, const Controls& controls, GameStatistics* gs)
    : IScene(ctx), controls_(controls), gs_(gs) {}
