/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:48:19 by schuah            #+#    #+#             */
/*   Updated: 2022/08/29 11:15:23 by schuah           ###   ########.fr       */
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
		AMateria		*temp;
		AMateria		*temp2;
		IMateriaSource	*materia = new MateriaSource();
		ICharacter		*me2 = new Character("me2");
		
		materia->learnMateria(new Ice());
		materia->learnMateria(new Cure());
		temp = materia->createMateria("ice");
		me2->equip(temp);
		temp = materia->createMateria("iice");
		if (temp == NULL)
			std::cout << "No such materia" << std::endl;
		for (int i = 0; i < 3; i++)
		{
			temp = materia->createMateria("cure");
			me2->equip(temp);
			me2->use(i, *me2);
		}
		temp2 = materia->createMateria("ice");
		me2->equip(temp2);
		me2->unequip(2);
		std::cout << "entering" << std::endl;
		for (int i = 0; i < 4; i++)
		{
			std::cout << "Slot " << i << ": ";
			me2->use(i, *me2);
		}
		std::cout << std::endl;
		delete temp2;
		delete materia;
		delete me2;
	}
	return (0);
}
