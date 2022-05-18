#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	FragTrap	APlayer("Aplayer");
	FragTrap	BPlayer("Bplayer");

    BPlayer.beRepaired(10);
	APlayer.attack("Bplayer");
	BPlayer.takeDamage(APlayer.getAttackDamage());
	BPlayer.beRepaired(10);
	BPlayer.beRepaired(10);
    APlayer.beRepaired(10);
	BPlayer.attack("Aplayer");
	APlayer.takeDamage(BPlayer.getAttackDamage());
	APlayer.highFivesGuys();
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