var assert = require('assert');
var solution082 = require('../src/euler/solution082');

describe('Solution082', function() {
  describe('answer', function() {
    it('will answer problem 082', function() {
      assert.equal(solution082.answer(), 260324);
    });
  });
});