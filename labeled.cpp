#include "labeled.h"

#include "basic.h"

Labeled::Labeled()
:_label(Basic::instance()->getNextLabelCounter())
{}

std::string Labeled::getLabel() const
{
    return _label;
}