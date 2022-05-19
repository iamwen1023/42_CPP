#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap	APlayer("Aplayer");
	DiamondTrap	BPlayer("Bplayer");

	std::cout<< APlayer.getName() << std::endl;
	std::cout<< BPlayer.getName() << std::endl;
	std::cout<<"Aplayer: attackpoint/hitpoint/energypoint : " 
			<< APlayer.getAttackDamage() << "/" 
			<< APlayer.getHitPoints() << "/" 
			<< APlayer.getEnergyPoints() << std::endl;
	std::cout<<"Bplayer: attackpoint/hitpoint/energypoint : " 
			<< BPlayer.getAttackDamage() << "/" 
			<< BPlayer.getHitPoints() << "/" 
			<< BPlayer.getEnergyPoints() << std::endl;
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
	APlayer.highFivesGuys();
	APlayer.whoAmI();
	std::cout<<"Aplayer: attackpoint/hitpoint/energypoint : " 
			<< APlayer.getAttackDamage() << "/" 
			<< APlayer.getHitPoints() << "/" 
			<< APlayer.getEnergyPoints() << std::endl;
	std::cout<<"Bplayer: attackpoint/hitpoint/energypoint : " 
			<< BPlayer.getAttackDamage() << "/" 
			<< BPlayer.getHitPoints() << "/" 
			<< BPlayer.getEnergyPoints() << std::endl;
	APlayer = BPlayer;
	APlayer.whoAmI();
	return (0);
}