#include <BearLibTerminal.h>

#include <string>

#include "scenes/game_over_scene.h"
#include "scenes/game_scene.h"
#include "scenes/title_scene.h"

int main() {
  terminal_open();
  terminal_set(
      "window.title='Snake Game';"
      "window.size=60x30;");
  terminal_refresh();

  GameStatistics gs;
  Controls controls;
  Context ctx;
  SceneManager sm(ctx);

  sm.Put("title", new TitleScene(&ctx, controls, &gs));
  sm.Put("game_over", new GameOverScene(&ctx, controls, &gs));
  sm.Put("game", new GameScene(&ctx, controls, &gs));
  ctx.scene_ = "title";

  while (true) {
    terminal_clear();

    controls.OnUpdate();
    if (controls.IsPressed(TK_CLOSE)) {
      break;
    }

    sm.OnRender();
    controls.Reset();
  }
  sm.OnExit();
  terminal_close();
}
