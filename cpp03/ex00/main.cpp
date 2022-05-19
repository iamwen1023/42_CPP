#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap	APlayer("Aplayer");
	ClapTrap	BPlayer("Bplayer");

    BPlayer.beRepaired(10);
	APlayer.attack("Bplayer");
    if (APlayer.getAttackDamage() > 0 && APlayer.getEnergyPoints() > 0)
    {
        BPlayer.takeDamage(APlayer.getAttackDamage());
    }
	BPlayer.beRepaired(10);
	BPlayer.beRepaired(10);
    APlayer.beRepaired(10);
	BPlayer.attack("Aplayer");
    if (BPlayer.getAttackDamage() > 0 && BPlayer.getEnergyPoints() > 0)
    {
	    APlayer.takeDamage(BPlayer.getAttackDamage());
    }
    std::cout<<"Aplayer: hitpoint/energypoint/attackpoint : " 
			<< APlayer.getHitPoints() << "/" 
			<< APlayer.getEnergyPoints() << "/"
			<< APlayer.getAttackDamage() << std::endl;
	std::cout<<"Bplayer: hitpoint/energypoint/attackpoint : " 
			<< BPlayer.getHitPoints() << "/" 
			<< BPlayer.getEnergyPoints() << "/"
			<< BPlayer.getAttackDamage() << std::endl;
	return (0);
}