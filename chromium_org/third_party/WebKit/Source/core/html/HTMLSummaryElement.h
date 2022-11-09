/*
 * Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies)
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this library; see the file COPYING.LIB.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 *
 */

#ifndef HTMLSummaryElement_h
#define HTMLSummaryElement_h

#include "core/html/HTMLElement.h"

namespace blink {

class HTMLDetailsElement;

class HTMLSummaryElement FINAL : public HTMLElement {
public:
    static PassRefPtrWillBeRawPtr<HTMLSummaryElement> create(Document&);
    bool isMainSummary() const;
    virtual bool willRespondToMouseClickEvents() OVERRIDE;

private:
    explicit HTMLSummaryElement(Document&);

    virtual RenderObject* createRenderer(RenderStyle*) OVERRIDE;
    virtual void defaultEventHandler(Event*) OVERRIDE;
    virtual void didAddUserAgentShadowRoot(ShadowRoot&) OVERRIDE;
    HTMLDetailsElement* detailsElement() const;

    virtual bool supportsFocus() const OVERRIDE;
};

}

#endif // HTMLSummaryElement_h
