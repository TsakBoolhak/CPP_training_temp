
Inventory::Inventory() {

	for (size_t i = 0 ; i < INVENTORY_SIZE ; i++)
		(this->inv)[i] = NULL;

	return;
}

Inventory::Inventory(Inventory const & src) {

	for (size_t i = 0 ; i < INVENTORY_SIZE ; i++)
		(this->inv)[i] = NULL;
	*this = src;

	return ;
}
Inventory::~Inventory() {

	for (size_t i = 0 ; i < INVENTORY_SIZE ; i++)
		delete (this->inv)[i];

	return ;
}

AMateria	*Inventory::getMateria(int idx) const {

	if (idx >= 0 && idx < INVENTORY_SIZE)
		return (this->inv)[idx];
	else
		return NULL;
}

void	equip(AMateria* m) {

	size_t i = 0
	for ( ; i < INVENTORY_SIZE && (this->inv)[i] != NULL ; i++)
		;
	if ( i < INVENTORY_SIZE )
		(this->inv)[i] = m;
	else
		std::cout << "Inventory is full" << std::endl;

	return ;
}

void	Inventory::unequip(int idx) {

	if ( idx >= 0 && idx < INVENTORY_SIZE && (this->inv)[idx] != NULL )
		(this->idx)[idx] = NULL;
	else if ( idx >= 0 && idx < INVENTORY_SIZE )
		std::cout << "This inventory slot is alrdy empty" << std::endl;
	else
		std::cout << "You tried to unequip a wrong index of inventory" << std::endl;

	return ;
}

void	Inventory::use(int idx, ICharacter& target) const {

	if ( idx >= 0 && idx < INVENTORY_SIZE && (this->inv)[idx] != NULL )
		(this->inv)[idx]->use(target);
	else
		AMateria::use(target);

	return ;
}

Inventory &	Inventory::operator=( Inventory const & src ) {

	if (this != &src) {

		for (size_t i = 0 ; i < INVENTORY_SIZE ; i++) {

			delete (this->inv)[i];
			(this->inv)[i] = (rhs.inv)[i]->clone();
		}
	}

	return *this;
}
