#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap	APlayer("Aplayer");
	ClapTrap	BPlayer("Bplayer");

    BPlayer.beRepaired(10);
	APlayer.attack("Bplayer");
    if (APlayer.getAttackDamage() > 0 && APlayer.getEnergyPoints() > 0)
        BPlayer.takeDamage(APlayer.getAttackDamage());
	BPlayer.beRepaired(10);
	BPlayer.beRepaired(10);
    APlayer.beRepaired(10);
	BPlayer.attack("Aplayer");
    if (BPlayer.getAttackDamage() > 0 && BPlayer.getEnergyPoints() > 0)
	    APlayer.takeDamage(BPlayer.getAttackDamage());
    std::cout<<"Aplayer: attackpoint/hitpoint/energypoint : " 
			<< APlayer.getAttackDamage() << "/" 
			<< APlayer.getHitPoints() << "/" 
			<< APlayer.getEnergyPoints() << std::endl;
	std::cout<<"Bplayer: attackpoint/hitpoint/energypoint : " 
			<< BPlayer.getAttackDamage() << "/" 
			<< BPlayer.getHitPoints() << "/" 
			<< BPlayer.getEnergyPoints() << std::endl;
	return (0);
}