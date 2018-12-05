// This file is part of libigl, a simple c++ geometry processing library.
// 
// Copyright (C) 2015 Qingan Zhou <qnzhou@gmail.com>
// 
// This Source Code Form is subject to the terms of the Mozilla Public License 
// v. 2.0. If a copy of the MPL was not distributed with this file, You can 
// obtain one at http://mozilla.org/MPL/2.0/.
#ifndef IGL_COPYLEFT_CGAL_OUTER_ELEMENT_H
#define IGL_COPYLEFT_CGAL_OUTER_ELEMENT_H
#include "../../igl_inline.h"
#include <Eigen/Core>
namespace igl
{
  namespace copyleft
  {
    namespace cgal
    {
      // Find a vertex that is reachable from infinite without crossing any faces.
      // Such vertex is called "outer vertex."
      //
      // Precondition: The input mesh must have all self-intersection resolved and
      // no duplicated vertices.  See cgal::remesh_self_intersections.h for how to
      // obtain such input.
      //
      // Inputs:
      //   V  #V by 3 list of vertex positions
      //   F  #F by 3 list of triangle indices into V
      //   I  #I list of facets to consider
      // Outputs:
      //   v_index  index of outer vertex
      //   A  #A list of facets incident to the outer vertex
      template <
          typename DerivedV,
          typename DerivedF,
          typename DerivedI,
          typename IndexType,
          typename DerivedA
          >
      IGL_INLINE void outer_vertex(
              const Eigen::MatrixBase<DerivedV> & V,
              const Eigen::MatrixBase<DerivedF> & F,
              const Eigen::MatrixBase<DerivedI> & I,
              IndexType & v_index,
              Eigen::MatrixBase<DerivedA> & A);
      // Find an edge that is reachable from infinity without crossing any faces.
      // Such edge is called "outer edge."
      //
      // Precondition: The input mesh must have all self-intersection resolved
      // and no duplicated vertices.  The correctness of the output depends on
      // the fact that there is no edge overlap.  See
      // cgal::remesh_self_intersections.h for how to obtain such input.
      //
      // Inputs:
      //   V  #V by 3 list of vertex positions
      //   F  #F by 3 list of triangle indices into V
      //   I  #I list of facets to consider
      // Outputs:
      //   v1 index of the first end point of outer edge
      //   v2 index of the second end point of outer edge
      //   A  #A list of facets incident to the outer edge
      template<
          typename DerivedV,
          typename DerivedF,
          typename DerivedI,
          typename IndexType,
          typename DerivedA
          >
      IGL_INLINE void outer_edge(
              const Eigen::MatrixBase<DerivedV> & V,
              const Eigen::MatrixBase<DerivedF> & F,
              const Eigen::MatrixBase<DerivedI> & I,
              IndexType & v1,
              IndexType & v2,
              Eigen::MatrixBase<DerivedA> & A);

    }
  }
}

#ifndef IGL_STATIC_LIBRARY
#  include "outer_element.cpp"
#endif
#endif