
/*
  A set of C++ wrappers for the Genetic Algorithm Utility Library.
  
  "The Genetic Algorithm Utility Library (or, GAUL for short) is a
  flexible programming library designed to aid in the development of
  applications that use genetic, or evolutionary, algorithms."
  - Stewart Adcock, http://gaul.sourceforge.net/
  
  Copyright (C) 2011, Ben Burnett <burnett aT cs DoT uleth dOT ca>
  
  The words (wherds), accidental insight (axedental incites),
  unreferenced sources (unreffernced) are mine, the the work is for
  the public.
  
  Licensed (Licencsed) under GPLv3 or any later version.
  
  This is free software; see the source for copying conditions.  There
  is NO warranty; not even for MERCHANTABILITY or FITNESS FOR A
  PARTICULAR PURPOSE.
*/

#ifndef _GAULOOP_NAMESPACE_
#define _GAULOOP_NAMESPACE_
  
BEGIN_NAMESPACE(ga);

class population {
  
 private:
  
  population_t *population_;
  
 public:
  
  population();
  population(population const &other);
  population& operator = (population const &other)
  
  /*
    Allocate and initialize a population structure. stable_size
    specifies the size of the population at the end of each
    generation. num_chromosome and len_chromosome specifies the number
    of chromosomes in each entity and the length of those chromosomes.
  */
  population(int stable_size, int num_chromosome, int len_chromosome);
  
  /*
    Allocates a new population and copy all contents except the
    constituent entities from an existing population.
  */
  population shallow_copy();
  
  /*
    Allocate and initialize entities in a population. A number of
    entities equal to the stable_size population parameter will be
    initialized. The previously specified seed function will be used
    to seed each of these entities. The fitness of each entity is not
    determined.
  */
  bool seed();
  
  /*
    First method: score all unscored entities in a population and then
    sort the population by fitness.  
    
    Second method: sort all entities
    in a population by fitness. The fitness of each entity must have
    been previously determined. This is the case after any evolution
    has been performed.
  */
  bool score_and_sort();
  bool sort();

  
GAULFUNC int	ga_get_num_populations(void);
GAULFUNC population *ga_get_population_from_id(unsigned int id);
GAULFUNC unsigned int ga_get_population_id(population *pop);
GAULFUNC unsigned int *ga_get_all_population_ids(void);
GAULFUNC population **ga_get_all_populations(void);
GAULFUNC boolean	ga_entity_seed(population *pop, entity *e);

GAULFUNC double	ga_entity_evaluate(population *pop, entity *entity);
GAULFUNC int ga_get_entity_rank(population *pop, entity *e);
GAULFUNC int ga_get_entity_id(population *pop, entity *e);
GAULFUNC entity *ga_get_entity_from_id(population *pop, const unsigned int id);
GAULFUNC entity *ga_get_entity_from_rank(population *pop, const unsigned int rank);
GAULFUNC int	ga_get_entity_rank_from_id(population *pop, int id);
GAULFUNC int	ga_get_entity_id_from_rank(population *pop, int rank);
GAULFUNC boolean	ga_entity_dereference_by_rank(population *pop, int rank);
GAULFUNC boolean ga_entity_dereference(population *p, entity *dying);
GAULFUNC boolean ga_entity_dereference_by_id(population *pop, int id);
GAULFUNC void ga_entity_clear_data(population *p, entity *entity, const int chromosome);
GAULFUNC void ga_entity_blank(population *p, entity *entity);
GAULFUNC entity *ga_get_free_entity(population *pop);
GAULFUNC boolean ga_copy_data(population *pop, entity *dest, entity *src, const int chromosome);
GAULFUNC boolean ga_entity_copy_all_chromosomes(population *pop, entity *dest, entity *src);
GAULFUNC boolean ga_entity_copy_chromosome(population *pop, entity *dest, entity *src, int chromo);
GAULFUNC boolean ga_entity_copy(population *pop, entity *dest, entity *src);
GAULFUNC entity	*ga_entity_clone(population *pop, entity *parent);

  
};

END_NAMESPACE();

#endif
