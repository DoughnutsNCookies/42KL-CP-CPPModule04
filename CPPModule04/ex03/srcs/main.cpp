/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:48:19 by schuah            #+#    #+#             */
/*   Updated: 2022/08/27 21:34:00 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"

int	main(void)
{
	{
		std::cout << "\n---------- EX01 Main ----------\n" << std::endl;
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter* me = new Character("me");

		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);

		ICharacter* bob = new Character("bob");

		me->use(0, *bob);
		me->use(1, *bob);

		delete bob;
		delete me;
		delete src;
	}
	{
		std::cout << "\n---------- EX01 First Test ----------\n" << std::endl;
		AMateria	*temp;
		AMateria	*temp2;
		IMateriaSource* materia = new MateriaSource();
		ICharacter* me = new Character("me");
		
		materia->learnMateria(new Ice());
		materia->learnMateria(new Cure());
		temp = materia->createMateria("ice");
		me->equip(temp);
		temp = materia->createMateria("iice");
		if (temp == NULL)
			std::cout << "No such materia" << std::endl;
		for (int i = 0; i < 3; i++)
		{
			temp = materia->createMateria("cure");
			me->equip(temp);
		}
		temp2 = materia->createMateria("ice");
		me->equip(temp2);
		delete temp2;
		me->unequip(3);
		delete temp;
		for (int i = 0; i < 4; i++)
		{
			std::cout << "Slot " << i << ": ";
			me->use(i, *me);
		}
		std::cout << std::endl;
		delete me;
		delete materia;
	}
	return (0);
}
