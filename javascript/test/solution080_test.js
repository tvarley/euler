var assert = require('assert');
var solution080 = require('../src/euler/solution080');

describe('Solution080', function() {
  describe('answer', function() {
    it('will answer problem 080', function() {
      assert.equal(solution080.answer(), 40727);
    });
  });
});