// Movimento em "saltos", como no Crossy Road
// Cada tecla move exatamente um bloco (40 pixels)

const int TAM_BLOCO = 40;

if (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)) {
    player.pos.y -= TAM_BLOCO;   // p cima
}

if (IsKeyPressed(KEY_S) || IsKeyPressed(KEY_DOWN)) {
    player.pos.y += TAM_BLOCO;   // p baixo
}

if (IsKeyPressed(KEY_A) || IsKeyPressed(KEY_LEFT)) {
    player.pos.x -= TAM_BLOCO;   // esquerda
}

if (IsKeyPressed(KEY_D) || IsKeyPressed(KEY_RIGHT)) {
    player.pos.x += TAM_BLOCO;   // direita
}

// Impedir que o jogador saia da tela
if (player.pos.x < 0) player.pos.x = 0;
if (player.pos.y < 0) player.pos.y = 0;

if (player.pos.x > GetScreenWidth() - player.tamanho)
    player.pos.x = GetScreenWidth() - player.tamanho;

if (player.pos.y > GetScreenHeight() - player.tamanho)
    player.pos.y = GetScreenHeight() - player.tamanho;