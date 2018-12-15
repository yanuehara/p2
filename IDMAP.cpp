#include "IDMAP.h"

namespace cg {
	namespace vis {
		void IDMAP::project(){
			Reference<DataTable> projection = nullptr;
			//DistanceMatrix dmat = new DataTable(input.getData(), diss);

			int length = _input->getLength();
			for (int i = 0; i < length; i++)
				for (int j = 0; j < length; j++)
					dmat->setEntry(i, j, this->_dissimilarity->value(_input->getRow(i), _input->getRow(j)));

			if (ini == InitializationType.FASTMAP)
			{
				FastMap fastmap = new FastMap(2, dmat);
				fastmap.setInput(this.input);
				fastmap.setDissimilarity(this.dissimilarity);
				projection = fastmap.project();

				if (projection != null)
				{
					ForceScheme force = new ForceScheme(dimension, projection.getRowDimension());
					double error = Double.MAX_VALUE;

					for (int i = 0; i < this.nriterations; i++)
					{
						error = force.iteration(dmat, projection);
					}
				}
			}
		}
	}
}