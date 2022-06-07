#include "Card.h"

Card::Card(CardType type, const CardStats& stats)
{
    m_effect = type;
    m_stats = stats;
}

void Card::applyEncounter(Player& player) const
{
    CardType type = m_effect;
    switch (type)
    {
        case CardType::Battle:
        {
            bool playerWin = true;
            if(player.getAttackStrength() >= m_stats.force){ // player wins
                player.levelUp();
                player.addCoins(m_stats.loot);
            }
            else{ // player loses
                player.damage(m_stats.hpLossOnDefeat);
                playerWin = false;
            }
            printBattleResult(playerWin);
            break;
        }

        case CardType::Buff:
        {
            if(player.pay(m_stats.cost)){
                player.buff(m_stats.buff);
            }
            break;
        }

        case CardType::Heal:
        {
            if(player.pay(m_stats.cost)){
                player.heal(m_stats.heal);
            }
            break;
        }

        case CardType::Treasure: {
            int coins = m_stats.loot;
            player.addCoins(coins);
            break;
        }

        default:
            break;
    }
}

void Card::printInfo() const
{
    CardType type = m_effect;
    const CardStats &stats = m_stats;

    switch (type)
    {
        case CardType::Battle:
            printBattleCardInfo(stats);
            break;

        case CardType::Buff:
            printBuffCardInfo(stats);
            break;

        case CardType::Heal:
            printHealCardInfo(stats);
            break;

        case CardType::Treasure:
            printTreasureCardInfo(stats);
            break;

        default:
            break;
    }
}

