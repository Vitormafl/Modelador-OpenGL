#include "octree.h"

Octree loadOctree(std::string filename) {
    ifstream MyReadFile(filename);
    std::string octreeString;
    getline(MyReadFile, octreeString);

    MyReadFile.close();

    return Octree(octreeString);
}

Node* octreeUnion(Node* a, Node* b, Node* c) {
    if (a->objectIntersect == 0 and b->objectIntersect == 0) {
        c = a;
    }

    else if (a->objectIntersect == 2) {
        c = a;
    }

    else if (a->objectIntersect == 2) {
        c = b;
    }

    else if (a->objectIntersect == 1 and b->objectIntersect == 0) {
        c = a;
    }

    else if (a->objectIntersect == 0 and b->objectIntersect == 1) {
        c = b;
    }

    else if (a->objectIntersect == 1 and b->objectIntersect == 1) {
        for (int i = 0; i < 8; i++) {
            c->childNodes[i] = octreeUnion(a->childNodes[i], b->childNodes[i], c->childNodes[i]);
        }
    }

    return c;
}

Octree octreeUnion(Octree a, Octree b) {
    Octree c = Octree(a.center, a.halfSize, a.maxDepth);
    if (a.rootNode->objectIntersect == 0 and b.rootNode->objectIntersect == 0) {
        c.rootNode = a.rootNode;
    }

    else if (a.rootNode->objectIntersect == 2) {
        c.rootNode = a.rootNode;
    }

    else if (b.rootNode->objectIntersect == 2) {
        c.rootNode = b.rootNode;
    }

    else if (a.rootNode->objectIntersect == 1 and b.rootNode->objectIntersect == 0) {
        c.rootNode = a.rootNode;
    }

    else if (a.rootNode->objectIntersect == 0 and b.rootNode->objectIntersect == 1) {
        c.rootNode = b.rootNode;
    }

    else if (a.rootNode->objectIntersect == 1 and b.rootNode->objectIntersect == 1) {
        c.rootNode = a.rootNode;
        for (int i = 0; i < 8; i++) {
            c.rootNode->childNodes[i] = octreeUnion(a.rootNode->childNodes[i], b.rootNode->childNodes[i], c.rootNode->childNodes[i]);
        }
    }

    return c;
}

Node* octreeIntersection(Node* a, Node* b, Node* c) {
    if (a->objectIntersect == 0) {
        c = a;
    }

    else if (b->objectIntersect == 0) {
        c = b;
    }

    else if (a->objectIntersect == 2 and b->objectIntersect == 1) {
        c = b;
    }

    else if (a->objectIntersect == 1 and b->objectIntersect == 2) {
        c = a;
    }

    else if (a->objectIntersect == 2 and b->objectIntersect == 2) {
        c = a;
    }

    else if (a->objectIntersect == 1 and b->objectIntersect == 1) {
        for (int i = 0; i < 8; i++) {
            c->childNodes[i] = octreeIntersection(a->childNodes[i], b->childNodes[i], c->childNodes[i]);
        }
    }

    return c;
}

Octree octreeIntersection(Octree a, Octree b) {
    Octree c = Octree(a.center, a.halfSize, a.maxDepth);
    if (a.rootNode->objectIntersect == 0) {
        c.rootNode = a.rootNode;
    }

    else if (b.rootNode->objectIntersect == 0) {
        c.rootNode = b.rootNode;
    }

    else if (a.rootNode->objectIntersect == 2 and b.rootNode->objectIntersect == 1) {
        c.rootNode = b.rootNode;
    }

    else if (a.rootNode->objectIntersect == 1 and b.rootNode->objectIntersect == 2) {
        c.rootNode = a.rootNode;
    }

    else if (a.rootNode->objectIntersect == 2 and b.rootNode->objectIntersect == 2) {
        c.rootNode = a.rootNode;
    }

    else if (a.rootNode->objectIntersect == 1 and b.rootNode->objectIntersect == 1) {
        c.rootNode = a.rootNode;
        for (int i = 0; i < 8; i++) {
            c.rootNode->childNodes[i] = octreeIntersection(a.rootNode->childNodes[i], b.rootNode->childNodes[i], c.rootNode->childNodes[i]);
        }
    }

    return c;
}

Node* octreeDiference(Node* a, Node* b, Node* c) {
    if (a->objectIntersect == 0) {
        c = a;
    }

    else if (b->objectIntersect == 0) {
        c = b;
    }

    else if (a->objectIntersect == 2 and b->objectIntersect == 1) {
        c = b;
    }

    else if (a->objectIntersect == 1 and b->objectIntersect == 2) {
        c = a;
    }

    else if (a->objectIntersect == 2 and b->objectIntersect == 2) {
        c = a;
    }

    else if (a->objectIntersect == 1 and b->objectIntersect == 1) {
        for (int i = 0; i < 8; i++) {
            c->childNodes[i] = octreeDiference(a->childNodes[i], b->childNodes[i], c->childNodes[i]);
        }
    }

    return c;
}

Octree octreeDiference(Octree a, Octree b) {
    Octree c = Octree(a.center, a.halfSize, a.maxDepth);
    if (a.rootNode->objectIntersect == 0) {
        c.rootNode = a.rootNode;
    }

    else if (b.rootNode->objectIntersect == 0) {
        c.rootNode = a.rootNode;
    }

    else if (b.rootNode->objectIntersect == 2) {
        c.rootNode = new Node;
        c.rootNode->nodeDepth = a.rootNode->nodeDepth;
        c.rootNode->nodeCenter = a.rootNode->nodeCenter;
        c.rootNode->isLeaf = true;
        c.rootNode->parentNode = a.rootNode->parentNode;
        c.rootNode->objectIntersect = 0;
        for (int i = 0; i < 8; i++) {
            c.rootNode->childNodes[i] = nullptr;
        }
    }

    else if (a.rootNode->objectIntersect == 2 and b.rootNode->objectIntersect == 1) {
        c.rootNode = a.rootNode;
    }

    else if (a.rootNode->objectIntersect == 1 and b.rootNode->objectIntersect == 1) {
        c.rootNode = a.rootNode;
        for (int i = 0; i < 8; i++) {
            c.rootNode->childNodes[i] = octreeDiference(a.rootNode->childNodes[i], b.rootNode->childNodes[i], c.rootNode->childNodes[i]);
        }
    }

    return c;
}