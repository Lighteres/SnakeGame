#include "scenes/game_over_scene.h"

#include <string>

static void PrintGameOver(Context* ctx, const Controls& controls, GameStatistics* gs) {
  terminal_clear();

  std::string strStep = std::to_string(gs->score_);
  const char* charStep = strStep.c_str();

  terminal_print(25, 4, "Game Over!");
  if (gs->IsGoodGameOver) {
    terminal_print(8, 5, "Congratulations! You have completed the game!");
    gs->IsGoodGameOver = false;
  } else {
    terminal_print(21, 5, "Sorry, but you lost");
  }

  terminal_print(24, 10, "Score:");
  terminal_print(31, 10, charStep);
  terminal_print(15, 19, "Press Enter to go to main menu");

  if (controls.IsPressed(TK_ENTER)) {
    gs->score_ = 0;
    std::fill_n(gs->tails, 1044, nullptr);
    gs->IsGameOver = false;
    gs->x = 0;
    gs->y = 0;
    gs->pX = 0;
    gs->pY = 0;
    gs->n_ = 0;
    gs->m_ = 0;
    gs->AddFruit = true;
    gs->AddTail = false;
    ctx->scene_ = "title";
  }

  terminal_refresh();
}

void GameOverScene::OnCreate() {}
void GameOverScene::OnRender() {
  PrintGameOver(ctx_, controls_, gs_);
}
void GameOverScene::OnExit() {}

GameOverScene::GameOverScene(Context* ctx, const Controls& controls, GameStatistics* gs)
    : IScene(ctx), controls_(controls), gs_(gs) {}
