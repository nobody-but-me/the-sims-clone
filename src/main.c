
// #include <raymath.h>
#include <raylib.h>
#include <raymath.h>
#include <stdio.h>

#define WINDOW_HEIGHT 600
#define WINDOW_WIDTH 1024

Vector2 CAMERA_TARGET = (Vector2){WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2};
Vector2 CAMERA_OFFSET = (Vector2){WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2};
float CAMERA_ROTATION = 0.0f;
float CAMERA_ZOOM     = 0.5f;

void _camera_move();

typedef struct _player {
    Texture2D _texture;
    Vector2 _position;
    float _rotation;
    Vector2 _scale;
} PLAYER;

int main() {
    printf("Hello, World! \n");
    
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "The Sims");
    SetWindowState(FLAG_WINDOW_RESIZABLE);
    
    Image _player_image = LoadImage("./assets/player.png");
    
    PLAYER _player;
    _player._texture = LoadTextureFromImage(_player_image);
    _player._position = (Vector2){-500.0f, -200.0f};
    _player._scale = (Vector2){150.0f, 150.0f};
    _player._rotation = 0.0f;
    
    Camera2D _camera = { 0 };
    _camera.target = CAMERA_TARGET;
    _camera.offset = CAMERA_OFFSET;
    _camera.rotation = CAMERA_ROTATION;
    _camera.zoom = CAMERA_ZOOM;
    
    SetTargetFPS(60);
    while (!WindowShouldClose()) {
	
	_camera_move();
	_camera.target = CAMERA_TARGET;
	
	BeginDrawing();
	
	ClearBackground((Color){7, 7, 7, 255});
	
	BeginMode2D(_camera);
	
	DrawTexturePro(_player._texture, (Rectangle){0.0f, 0.0f, 16.0f, 16.0f}, (Rectangle){0.0f, 0.0f, _player._scale.x, _player._scale.y}, (Vector2){_player._position.x, _player._position.y}, _player._rotation, WHITE);
	
	EndMode2D();
	
	if (IsKeyPressed(KEY_END)) {
	    CloseWindow();
	}
	
	EndDrawing();
    }
    CloseWindow();
    return 0;
}

void _camera_move() {
    if (IsKeyDown(KEY_W)) {
	CAMERA_TARGET.y -= 10.0f;
    }
    if (IsKeyDown(KEY_S)) {
	CAMERA_TARGET.y += 10.0f;
    }
    if (IsKeyDown(KEY_D)) {
	CAMERA_TARGET.x += 10.0f;
    }
    if (IsKeyDown(KEY_A)) {
	CAMERA_TARGET.x -= 10.0f;
    }
    
    return;
}
