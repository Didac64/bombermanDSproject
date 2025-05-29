#include "bombamanager.h"
#include "enemigos.h"

Bombamanager::Bombamanager(int spriteID)
{
	_spriteID = spriteID;	
}
Bombamanager::~Bombamanager()
{
}
void Bombamanager::crearbombas(int x, int y)
{
	bombas.push_back(new Bomba(x, y, _spriteID));
}

void Bombamanager::update(Enemigos* enemigo)
{
    auto it = bombas.begin();
    while (it != bombas.end())
    {
        Bomba* bomba = *it;
        bomba->update();

        // Verificar colisión con el enemigo SOLO si explota
        if (bomba->GetExplota())
        {
            // Comprobar si el enemigo está cerca (por posición exacta o por rango)
            if (bomba->GetPosX() == enemigo->GetPosX()&&
                bomba->GetPosY() == enemigo->GetPosY())
            {
                enemigo->SetStateLife(false);
            }

            // Eliminar bomba después de explotar
            it = bombas.erase(it);  // elimina y avanza
        }
        else
        {
            ++it; // avanzar solo si no se borra
        }
    }
}

void Bombamanager::Render()
{
	for (int i = 0; i < bombas.size(); i++)
	{
		bombas[i]->Render();
	}

}
